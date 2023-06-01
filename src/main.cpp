#include "Arduino.h"
//#include "FS.h"
//#include "SPIFFS.h"
#include "JeeUI2.h"


bool rst = false;
unsigned long tm;

void restart_handle();
void interface();
void update();


//настройка входных контактов
const int buttonPin1 = 32;                    // габариты
const int buttonPin2 = 35;                    // левая
const int buttonPin3 = 34;                    // правая
//настройка переменных для удержания состояния кнопки, предыдущего состояния кнопки и состояния анимации
int buttonState1 = 0;
int stateB1 = 0;
int buttonState2 = 0;
int stateB2 = 0;
int buttonState3 = 0;
int stateB3 = 0;

unsigned long timing;
unsigned long timing2;


#define NUM_LEDS 30
#include <Adafruit_NeoPixel.h>
#define PINA 4
#define PINB 5
#define FASTLED_ALLOW_INTERRUPTS 0
Adafruit_NeoPixel ledsA(NUM_LEDS, PINA, NEO_GRB + NEO_KHZ800); //левая
Adafruit_NeoPixel ledsB(NUM_LEDS, PINB, NEO_GRB + NEO_KHZ800); // правая

jeeui2 jee;
#include "interface.h"  // в этот файл вынесена работа с параметрами и с веб интерфейсом
#include "effects.h"  // в этот файл вынесена работа єффектов

void setup() {
  //Serial.begin(115200);
  //SPIFFS.begin(true);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
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
 
}
void btnUI()
{
  jee.var("wifi", "STA");
  jee.save();
  rst = true;
  tm = millis();
}

void loop() {
  //Serial.print(digitalRead(buttonPin1));Serial.print("\t");
  //Serial.print(digitalRead(buttonPin2));Serial.print("\t");
  //Serial.println(digitalRead(buttonPin3));
  buttonState1 = digitalRead(buttonPin1);
  if(buttonState1 == HIGH){stateB1 = 1;} else {stateB1 = 0;}
  if(stateB1 == 1){
    //effects();
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
    
    if(buttonState2 == HIGH){stateB2 = 1;} else 
      if (buttonState2 == LOW){timing = millis(); stateB2 = 0;}
    if(buttonState3 == HIGH){stateB3 = 1;} else 
      if (buttonState3 == LOW){timing2 = millis(); stateB3 = 0;}
   // if(stateB2 == 0 && stateB3 == 0){effects();}
    if(stateB2 == 1 && stateB3 == 0){
      //OutsideToCenterB(0xff, 69, 0, 4, 80, 100);
      one_color_B();
      } 
    if(stateB3 == 1 && stateB2 == 0){
      //OutsideToCenterA(0xff, 69, 0, 4, 80, 100);
      one_color_A();
      } 
    if(stateB2 == 1 && stateB3 == 1){
      //OutsideToCenterAvar(0xff, 69, 0, 4, 80, 100);
      one_color_avar();
      } 
    if(stateB2 == 0 && stateB3 == 0){ effects();}
      } else {
        buttonState2 = digitalRead(buttonPin2);
        buttonState3 = digitalRead(buttonPin3);
        if(buttonState2 == HIGH){stateB2 = 1;} else {stateB2 = 0;}
        if(buttonState3 == HIGH){stateB3 = 1;} else {stateB3 = 0;}
        if(stateB2 == 0 && stateB3 == 0){one_color_all(0, 0, 0);    ledsA.show();  ledsB.show();}
        if(stateB2 == 1 && stateB3 == 0){
          //OutsideToCenterBoff(0xff, 69, 0, 4, 80, 100);
          one_color_Boff();
          } 
        if(stateB3 == 1 && stateB2 == 0){
          //OutsideToCenterAoff(0xff, 69, 0, 4, 80, 100);
          one_color_Aoff();
          } 
        if(stateB2 == 1 && stateB3 == 1){
          //OutsideToCenterAvar(0xff, 69, 0, 4, 80, 100);
          one_color_avar();
          } 
    
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
