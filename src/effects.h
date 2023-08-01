   /// NEW

//***************************************************
//***************************************************
// Функция для переконвертации значения цвета HEX в RGB
void hexToRGB(const char *hexValue, byte &r, byte &g, byte &b) {
  // Преобразуем HEX-строку в числовое значение
  unsigned long hexNumber = strtoul(hexValue, NULL, 16);
  
  // Извлекаем значения красного, зеленого и синего
  r = (hexNumber >> 16) & 0xFF;
  g = (hexNumber >> 8) & 0xFF;
  b = hexNumber & 0xFF;
}
#include "effects2.h"  // в этот файл вынесена работа старых эффектов
  void dxos1 ()
{ //Увеличивает яркость первого поворотника до максимального значения для режима ДХО
  hexToRGB(&colorA[1], rA, gA, bA);
  for (int j = 0; j < Brgh; j += gradation)
  {
    ledsA.setBrightness(j);
    for (int x = 0; x < 30; x++) {
      if (led_arrayA[x] == 0) {
           ledsA.setPixelColor(x, ledsA.Color(0, 0, 0));
      } else {
          ledsA.setPixelColor(x, ledsA.Color(rA, gA, bA));
      }
  }
    ledsA.show();
    set5 = 0;
  }
   //Serial.println("Сработал dxos12");
  set10 = 0;
}
  void dxos2()
{ //Увеличивает яркость второго поворотника до максимального значения для режима ДХО.
  hexToRGB(&colorB[1], rB, gB, bB);
  for (int j = 0; j < Brgh; j += gradation)
  {
    ledsB.setBrightness(j);
    for (int y = 0; y < 30; y++) {
      if (led_arrayB[y] == 0) {
          ledsB.setPixelColor(y, ledsB.Color(0, 0, 0));
      } else {
          ledsB.setPixelColor(y, ledsB.Color(rB, gB, bB));
      }
  }
    ledsB.show();
    set5 = 0;
  }
   //Serial.println("Сработал dxos22");
  set9 = 0;
}
   void dxos3 ()
{ //Увеличивает яркость обоих поворотников до максимального значения для режима ДХО.
  for (int j = 0; j < Brgh; j += gradation)
  {
    ledsA.setBrightness(j);
    ledsB.setBrightness(j);
    effects();
    //Serial.println("Сработал dxos32");
    set5 = 0;
  }
  set9 = 0;
  set10 = 0;
}
 //***************************************************
//***************************************************

void turnoff1()
{ //Выключает первый поворотник, выключая все светодиоды на его ленте.
  for (int l = 0; l < NUM_LEDS_all; l ++)
  {
    ledsA.setPixelColor(l, ledsA.Color(0, 0, 0));
  }
  ledsA.show();
  set1 = 1; set3 = 0;
}
void turnoff2 ()
{ //Выключает второй поворотник, выключая все светодиоды на его ленте.
  for (int l = 0; l < NUM_LEDS_all; l ++)
  {
    ledsB.setPixelColor(l, ledsB.Color(0, 0, 0));
  }
  ledsB.show();
  set2 = 1; set3 = 0;
}
//***************************************************
//***************************************************
   void dxooff ()
{ //Выключает оба поворотника при выключении режима ДХО.
  for (int i = 0; i < NUM_LEDS_all + 1; i++)
  {
    ledsA.setPixelColor(i, ledsA.Color(0, 0, 0));
    ledsB.setPixelColor(i, ledsB.Color(0, 0, 0));
  }
  ledsA.show(); ledsB.show();
  set1 = 1;  // Флаг, указывающий на активность первого поворотника
  set2 = 1; // Флаг, указывающий на активность второго поворотника
  set3 = 0; // Флаг, указывающий на активность эффекта мерцания при включении обоих поворотников
}
//***************************************************

// Функции управления отображением эффектов на светодиодных лентах
void turn1()
{//Отображает эффект первого поворотника (желтая анимация пробегания светодиодов) и переключает в режим ДХО при необходимости.
   hexToRGB(&color_rep[1], r_rep, g_rep, b_rep);
  if (set9 == 1 && digitalRead(DRLSignal) == HIGH)
  {
    dxos2(); //Увеличивает яркость второго поворотника до максимального значения для режима ДХО.
  }
  else
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      ledsA.setPixelColor(i, ledsA.Color(r_rep, g_rep, b_rep));
    }
      ledsA.show();  
      set5 = 1; set1 = 0; set10 = 1;
    if (digitalRead(LeftSignal) == LOW)
    {
      turnoff1(); //Выключает первый поворотник, выключая все светодиоды на его ленте.
    }
  }
}
//***************************************************
//***************************************************
void turn2 () 
{ // Поворотник 2
  hexToRGB(&color_rep[1], r_rep, g_rep, b_rep);
  if (set10 == 1 && digitalRead(DRLSignal) == HIGH)
  {
    dxos1();
  }
  else
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      ledsB.setPixelColor(i, ledsB.Color(r_rep, g_rep, b_rep));    

    }
      ledsB.show();
    set5 = 1; set2 = 0; set9 = 1;  
    
    if (digitalRead(RightSignal) == LOW)
    {
      turnoff2();
    }
  }
}
//***************************************************
//***************************************************

void turncrash1()
{ // Отображает эффект мерцания обоих поворотников, 
//активируется при одновременной активации обоих поворотников.
  hexToRGB(&color_rep[1], r_rep, g_rep, b_rep);
  if (set3 == 0)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      ledsA.setPixelColor(i, ledsA.Color(r_rep, g_rep, b_rep));
      ledsB.setPixelColor(i, ledsB.Color(r_rep, g_rep, b_rep));
    }
    ledsA.show();
    ledsB.show();
    set9 = 1; set10 = 1;
    set2 = 1;
    set3 = 1;
  }
}
void turncrash11()
{	//Завершает эффект мерцания обоих поворотников, 
	//отображая статические желтые светодиоды на середине и краях ленты.
   if (digitalRead(RightSignal) == LOW and digitalRead(LeftSignal) == LOW)
  {
    dxooff();
    time1 = millis();
  }
}

 
//***************************************************
//***************************************************

void start() //TODO доделать
{ //Отображает специальный эффект при включении 
	//(последовательное включение и выключение светодиодов на ленте ДХО).
  hexToRGB(&colorA[1], rA, gA, bA);
  hexToRGB(&colorB[1], rB, gB, bB);
  hexToRGB(&colorA2[1], rA2, gA2, bA2);
  hexToRGB(&colorB2[1], rB2, gB2, bB2);
  dxooff();
  Z = NUM_LEDS_all + 1;
  for (int count = 0; count < NUM_LEDS_all; count++) {
    for (int i = 0; i < NUM_LEDS_all; i++) {
      Z = Z - 1;
      ledsA.setBrightness(255);
      ledsA.setPixelColor(Z - 1, ledsA.Color(rA, gA, bA));
      ledsA.show();
      ledsB.setBrightness(255);
      ledsB.setPixelColor(Z - 1, ledsB.Color(rB, gB, bB));
      ledsB.show();
      delay(3);
      ledsA.setBrightness(255);
      ledsA.setPixelColor(Z - 1, ledsA.Color(0, 0, 0));
      ledsA.show();
      ledsB.setBrightness(255);
      ledsB.setPixelColor(Z - 1, ledsB.Color(0, 0, 0));
      ledsB.show();
    }
    ledsA.setBrightness(255);
    ledsA.setPixelColor(Z - 1, ledsA.Color(rA, gA, bA));
    ledsA.show();
    ledsB.setBrightness(255);
    ledsB.setPixelColor(Z - 1, ledsB.Color(rB, gB, bB));
    ledsB.show();
    Z = NUM_LEDS_all + (Z + 1);
  }
  delay(2);
Z = 0;
  for (int count = 0; count < NUM_LEDS_all; count++) {
    Z = Z + 1;
    ledsA.setBrightness(255);
	  ledsB.setBrightness(255);
    ledsA.setPixelColor(Z - 1, ledsA.Color(0, 128, 255));
	  ledsB.setPixelColor(Z - 1, ledsB.Color(0, 128, 255));
    ledsA.show();
	  ledsB.show();
    delay(10);
    ledsA.setBrightness(255);
	  ledsB.setBrightness(255);
    ledsA.setPixelColor(Z - 1, ledsA.Color(rA, gA, bA));
	  ledsB.setPixelColor(Z - 1, ledsB.Color(rB, gB, bB));
    ledsA.show();
	  ledsB.show();
  }
  Z = NUM_LEDS_all;
  for (int i = 0; i < NUM_LEDS_all; i++) {
    Z = Z - 1;
    ledsA.setBrightness(255);
	  ledsB.setBrightness(255);
    ledsA.setPixelColor(Z - 1, ledsA.Color(0, 128, 255));
	  ledsB.setPixelColor(Z - 1, ledsB.Color(0, 128, 255));
    ledsA.show();
	  ledsB.show();
    delay(10);
  }
  ledsA.setPixelColor(30, ledsA.Color(rA2, gA2, bA2));
  ledsB.setPixelColor(30, ledsB.Color(rB2, gB2, bB2));
  ledsA.show();
  ledsB.show();
  dxos3();
}  
 