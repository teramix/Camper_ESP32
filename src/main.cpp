#include "Arduino.h"
//#include "FS.h"
//#include "SPIFFS.h"
#include "JeeUI2.h"
#include <Adafruit_NeoPixel.h>

bool rst = false;
unsigned long tm;

void restart_handle();
void interface();
void update();


//настройка входных контактов
const int DRLSignal = 32;                    // габариты
const int LeftSignal = 35;                    // левая
const int RightSignal = 34;                    // правая
//настройка переменных для удержания состояния кнопки, предыдущего состояния кнопки и состояния анимации
//int buttonState1 = 0;
//int stateB1 = 0;
//int buttonState2 = 0;
//int stateB2 = 0;
//int buttonState3 = 0;
//int stateB3 = 0;
boolean set1 = 1;  // Флаг, указывающий на активность первого поворотника
boolean set2 = 1;  // Флаг, указывающий на активность второго поворотника
boolean set3 = 0;  // Флаг, указывающий на активность эффекта мерцания при включении обоих поворотников
boolean set4 = 0;  // Флаг, указывающий на активность режима ДХО (фары ближнего света)
boolean set5 = 0;  // Флаг, указывающий на активность переключения режимов (некоторые функции его используют)
boolean set6 = 0;  // Флаг, указывающий на активность переключения первого поворотника в режим ДХО
boolean set7 = 0;  // Флаг, указывающий на активность переключения второго поворотника в режим ДХО
boolean set8 = 0;  // Флаг, указывающий на активность эффекта мерцания при включении обоих поворотников в режим ДХО
boolean set9 = 0;  // Флаг, указывающий на активность переключения второго поворотника в режим пробегания
boolean set10 = 0; // Флаг, указывающий на активность переключения первого поворотника в режим пробегания

#define  setback    600   // Время задержки переключения на ДХО
#define  gradation  4     // Градация увеличения яркости (чем больше тем быстрее будет достикнута макс. яркость)
#define  speed1     15    // Скорость пробегания при включении ДХО

//unsigned long timing;
//unsigned long timing2;
unsigned long time1;   // Таймер 1
long Z = 0;


#define NUM_LEDS 30 // количество пикселей поворотник
#define NUM_LEDS_all 31 // количество пикселей поворотник с центральным
#define PINA 4
#define PINB 5
//#define FASTLED_ALLOW_INTERRUPTS 0
Adafruit_NeoPixel ledsA(NUM_LEDS_all, PINA, NEO_GRB + NEO_KHZ800); //левая
Adafruit_NeoPixel ledsB(NUM_LEDS_all, PINB, NEO_GRB + NEO_KHZ800); // правая

jeeui2 jee;
#include "interface.h"  // в этот файл вынесена работа с параметрами и с веб интерфейсом
#include "effects.h"  // в этот файл вынесена работа єффектов

void setup() {
  //Serial.begin(115200);
  //SPIFFS.begin(true);
  pinMode(DRLSignal, INPUT); // ДХО (+12V от лампочки ходового огня или кнопки через делитель напряжения)
  pinMode(LeftSignal, INPUT); // Поворотник A (+12V от лампочки поворотника 1 через делитель напряжения)
  pinMode(RightSignal, INPUT); // Поворотник B (+12V от лампочки поворотника 2 через делитель напряжения)
  jee.ap(5000);
  parameters();
  jee.ui(interface);
  jee.update(update);
  jee.begin(true);
  ledsA.begin();
  ledsB.begin();
  ledsA.setBrightness(255);
  ledsB.setBrightness(255);
  rainbow_loop();
  start(); // Запускаем функцию, которая отображает специальный эффект при включении
  delay(800);
  if (digitalRead(DRLSignal) == HIGH) // Если ДХО активно, то устанавливаем соответствующее состояние
  {
    set4 = 1; // Флаг, указывающий на активность режима ДХО (фары ближнего света)
  }
  else  {
    dxooff(); // Иначе выключаем ДХО
  }
 
}
void btnUI()
{
  jee.var("wifi", "STA");
  jee.save();
  rst = true;
  tm = millis();
}

void loop() {
  // Отслеживаем состояния поворотников и режимов
	// и выполняем соответствующие функции для отображения эффектов на светодиодных лентах
  if (digitalRead(LeftSignal) == HIGH and digitalRead(RightSignal) == LOW)
  {
    turn1();
    time1 = millis();
    set6 = 1; // Флаг, указывающий на активность переключения первого поворотника в режим ДХО
  }
  if (digitalRead(LeftSignal) == LOW and digitalRead(RightSignal) == HIGH )
  {
    turn2();
    time1 = millis();
    set7 = 1; // Флаг, указывающий на активность переключения второго поворотника в режим ДХО
  }
  if (digitalRead(LeftSignal) == HIGH and digitalRead(RightSignal) == HIGH)
  {
    turncrash1();
    time1 = millis();
  }
  if (set3 == 1) // Флаг, указывающий на активность эффекта мерцания при включении обоих поворотников
  {
    turncrash11();
    set8 = 1;// Флаг, указывающий на активность эффекта мерцания при включении обоих поворотников в режим ДХО
  }
  //////////////////////////////////////////////////////

  // Проверяем состояние ДХО и управляем его работой при необходимости
  if (digitalRead(DRLSignal) == LOW and set6 == 1) set6 = 0; // Флаг, указывающий на активность переключения первого поворотника в режим ДХО
  if (digitalRead(DRLSignal) == LOW and set7 == 1) set7 = 0; // Флаг, указывающий на активность переключения второго поворотника в режим ДХО
  if (digitalRead(DRLSignal) == LOW and set8 == 1) set8 = 0; // Флаг, указывающий на активность эффекта мерцания при включении обоих поворотников в режим ДХО


  //////////////////////////////////////////////////////

  if (digitalRead(DRLSignal) == HIGH and set6 == 1 and set10 == 1 and millis() - time1 > setback + 150)
  {
    time1 = millis();
    dxos1(); //Увеличивает яркость первого поворотника до максимального значения для режима ДХО.
    set6 = 0;
  }
  if (digitalRead(DRLSignal) == HIGH and set7 == 1 and set9 == 1 and millis() - time1 > setback + 150)
  {
    time1 = millis();
    dxos2(); //Увеличивает яркость второго поворотника до максимального значения для режима ДХО.
    set7 = 0;
  }
  if (digitalRead(DRLSignal) == HIGH and set8 == 1 and millis() - time1 > setback)
  {
    time1 = millis();
    dxos3(); //Увеличивает яркость обоих поворотников до максимального значения для режима ДХО.
    set8 = 0;
  }
  //////////////////////////////////////////////////////

  if (digitalRead(DRLSignal) == HIGH and set4 == 0)
  {
    start();
    set4 = 1;
  }
  if (digitalRead(DRLSignal) == LOW and set4 == 1)
  {
    dxooff(); //Выключает все ленты при выключении режима ДХО.
    set4 = 0;
  }



  jee.handle();
  restart_handle();
  jee.btnCallback("btn1", btnUI);
  //effects();
  
}
void restart_handle()
{
  if (!rst)
    return;
  if (tm + 2000 > millis())
    return;
  ESP.restart();
}
