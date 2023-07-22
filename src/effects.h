   /// NEW
  long long numberA = strtoll( &colorA[1], NULL, 16); //цвет светодиодов
  long long numberB = strtoll( &colorB[1], NULL, 16);
  long long rA = numberA >> 16;
  long long gA = numberA >> 8 & 0xFF;
  long long bA = numberA & 0xFF;  
  long long rB = numberB >> 16;
  long long gB = numberB >> 8 & 0xFF;
  long long bB = numberB & 0xFF;
  long long numberA2 = strtoll( &colorA2[1], NULL, 16); //цвет центра фары
  long long numberB2 = strtoll( &colorB2[1], NULL, 16);
  long long rA2 = numberA2 >> 16;
  long long gA2 = numberA2 >> 8 & 0xFF;
  long long bA2 = numberA2 & 0xFF;  
  long long rB2 = numberB2 >> 16;
  long long gB2 = numberB2 >> 8 & 0xFF;
  long long bB2 = numberB2 & 0xFF;
  long long number_rep = strtoll( &color_rep[1], NULL, 16); //цвет поворотников
  long long r_rep = number_rep >> 16;
  long long g_rep = number_rep >> 8 & 0xFF;
  long long b_rep = number_rep & 0xFF;

//***************************************************
//***************************************************

  void dxos1 ()
{ //Увеличивает яркость первого поворотника до максимального значения для режима ДХО
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
  set10 = 0;
}
  void dxos2()
{ //Увеличивает яркость второго поворотника до максимального значения для режима ДХО.
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
  set9 = 0;
}
   void dxos3 ()
{ //Увеличивает яркость обоих поворотников до максимального значения для режима ДХО.
  for (int j = 0; j < Brgh; j += gradation)
  {
    ledsA.setBrightness(j);
    ledsB.setBrightness(j);
    for (int x = 0; x < 30; x++) {
      if (led_arrayA[x] == 0) {
           ledsA.setPixelColor(x, ledsA.Color(0, 0, 0));
      } else {
          ledsA.setPixelColor(x, ledsA.Color(rA, gA, bA));
      }
  }
  if (led_arrayA[30] == 0) { //центр  А
           ledsA.setPixelColor(30, ledsA.Color(0, 0, 0));
      } else {
          ledsA.setPixelColor(30, ledsA.Color(rA2, gA2, bA2));
      }
  for (int y = 0; y < 30; y++) {
      if (led_arrayB[y] == 0) {
          ledsB.setPixelColor(y, ledsB.Color(0, 0, 0));
      } else {
          ledsB.setPixelColor(y, ledsB.Color(rB, gB, bB));
      }
  }
  if (led_arrayB[30] == 0) { //центр  Б
           ledsB.setPixelColor(30, ledsB.Color(0, 0, 0));
      } else {
          ledsB.setPixelColor(30, ledsB.Color(rB2, gB2, bB2));
      }
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
      delay(5);
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
  delay(1000);
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




   
   
    /// old
    int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
    int ihue = 0;                //-HUE (0-255)
    int thisdelay = 20;          //-FX LOOPS DELAY VAR
    int thisstep = 10;           //-FX LOOPS DELAY VAR
    int thishue = 0;             //-FX LOOPS DELAY VAR
    int thissat = 255;           //-FX LOOPS DELAY VAR

void one_color_all(int cred, int cgrn, int cblu) {       //Все светодиоды одним цветом
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    ledsA.setPixelColor(i, ledsA.Color(cred, cgrn, cblu));
    ledsB.setPixelColor(i, ledsB.Color(cred, cgrn, cblu));
  }
}
void one_color_allA(int cred, int cgrn, int cblu) {       //Фара А одним цветом
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    ledsA.setPixelColor(i, ledsA.Color(cred, cgrn, cblu));
  }
}
void one_color_allB(int cred, int cgrn, int cblu) {       //Фара Б одним цветом
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    ledsB.setPixelColor(i, ledsB.Color(cred, cgrn, cblu));
  }
}
void one_color_avar() {       //аварийка 
ledsA.setBrightness(Brgh);
ledsB.setBrightness(Brgh);
    long long number_rep = strtoll( &color_rep[1], NULL, 16);
    long long r_rep = number_rep >> 16;
    long long g_rep = number_rep >> 8 & 0xFF;
    long long b_rep = number_rep & 0xFF;
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsA.setPixelColor(i, ledsA.Color(r_rep, g_rep, b_rep));
    ledsB.setPixelColor(i, ledsB.Color(r_rep, g_rep, b_rep));
  }
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320); // задержка выключения аварийки TODO исправить
  one_color_all(0, 0, 0);
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320); // задержка включения аварийки TODO исправить
}
void one_color_A() {       // Заданый цвет фары А
ledsA.setBrightness(Brgh);
ledsB.setBrightness(Brgh);
    long long numberB = strtoll( &colorB[1], NULL, 16);
    long long rB = numberB >> 16;
    long long gB = numberB >> 8 & 0xFF;
    long long bB = numberB & 0xFF;
    long long number_rep = strtoll( &color_rep[1], NULL, 16);
    long long r_rep = number_rep >> 16;
    long long g_rep = number_rep >> 8 & 0xFF;
    long long b_rep = number_rep & 0xFF;
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsA.setPixelColor(i, ledsA.Color(r_rep, g_rep, b_rep));
  }
  for (int y = 0; y < NUM_LEDS; y++) {
    ledsB.setPixelColor(y, led_arrayB[y] == 0 ? ledsB.Color(0, 0, 0) : ledsB.Color(rB, gB, bB));
  }
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320); // TODO доделать

  one_color_allA(0, 0, 0);
  ledsA.show(); // Отобразить изменения на ленте ledsA
  //ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);
}

void one_color_B() {       // Весь цвет светодиода B
ledsA.setBrightness(Brgh);
ledsB.setBrightness(Brgh);
    long long numberA = strtoll( &colorA[1], NULL, 16);
    long long rA = numberA >> 16;
    long long gA = numberA >> 8 & 0xFF;
    long long bA = numberA & 0xFF;
    long long number_rep = strtoll( &color_rep[1], NULL, 16);
    long long r_rep = number_rep >> 16;
    long long g_rep = number_rep >> 8 & 0xFF;
    long long b_rep = number_rep & 0xFF;
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsB.setPixelColor(i, ledsB.Color(r_rep, g_rep, b_rep));
  }
  for (int y = 0; y < 30; y++) {
      if (led_arrayA[y] == 0) {
          ledsA.setPixelColor(y, ledsA.Color(0, 0, 0));
      } else {
          ledsA.setPixelColor(y, ledsA.Color(rA, gA, bA));
      }
  } 
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);

  one_color_allB(0, 0, 0);
  //ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);
}
void one_color_Aoff() {       // Выключены габариты светодиода А
 ledsA.setBrightness(Brgh);
    long long number_rep = strtoll( &color_rep[1], NULL, 16);
    long long r_rep = number_rep >> 16;
    long long g_rep = number_rep >> 8 & 0xFF;
    long long b_rep = number_rep & 0xFF;
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsA.setPixelColor(i, ledsA.Color(r_rep, g_rep, b_rep));
  }
  ledsA.show(); // Отобразить изменения на ленте ledsA
  delay(320);

  one_color_allA(0, 0, 0);
  ledsA.show(); // Отобразить изменения на ленте ledsA
  delay(320);
}
void one_color_Boff() {       // Выключены габариты светодиода B
ledsB.setBrightness(Brgh);
long long number_rep = strtoll( &color_rep[1], NULL, 16);
    long long r_rep = number_rep >> 16;
    long long g_rep = number_rep >> 8 & 0xFF;
    long long b_rep = number_rep & 0xFF;
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsB.setPixelColor(i, ledsB.Color(r_rep, g_rep, b_rep));
  }
 ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);

  one_color_allB(0, 0, 0);
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);
}

void led_default(){
    // Get rid of '#' and convert it to integer
  long long numberA = strtoll( &colorA[1], NULL, 16); //цвет светодиодов
  long long numberB = strtoll( &colorB[1], NULL, 16);
  long long rA = numberA >> 16;
  long long gA = numberA >> 8 & 0xFF;
  long long bA = numberA & 0xFF;
  
  long long rB = numberB >> 16;
  long long gB = numberB >> 8 & 0xFF;
  long long bB = numberB & 0xFF;
  long long numberA2 = strtoll( &colorA2[1], NULL, 16); //цвет центра фары
  long long numberB2 = strtoll( &colorB2[1], NULL, 16);
  long long rA2 = numberA2 >> 16;
  long long gA2 = numberA2 >> 8 & 0xFF;
  long long bA2 = numberA2 & 0xFF;
  
  long long rB2 = numberB2 >> 16;
  long long gB2 = numberB2 >> 8 & 0xFF;
  long long bB2 = numberB2 & 0xFF;
  ledsA.setBrightness(Brgh);
  ledsB.setBrightness(Brgh);
  for (int x = 0; x < 30; x++) {
      if (led_arrayA[x] == 0) {
           ledsA.setPixelColor(x, ledsA.Color(0, 0, 0));
      } else {
          ledsA.setPixelColor(x, ledsA.Color(rA, gA, bA));
      }
  }
  if (led_arrayA[30] == 0) {
           ledsA.setPixelColor(30, ledsA.Color(0, 0, 0));
      } else {
          ledsA.setPixelColor(30, ledsA.Color(rA2, gA2, bA2));
      }
  for (int y = 0; y < 30; y++) {
      if (led_arrayB[y] == 0) {
          ledsB.setPixelColor(y, ledsB.Color(0, 0, 0));
      } else {
          ledsB.setPixelColor(y, ledsB.Color(rB, gB, bB));
      }
  }
  if (led_arrayB[30] == 0) {
           ledsB.setPixelColor(30, ledsB.Color(0, 0, 0));
      } else {
          ledsB.setPixelColor(30, ledsB.Color(rB2, gB2, bB2));
      }
  
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
}
void rainbow_loop() {                        //крутящаяся радуга

  idex = (idex + 1) % NUM_LEDS;
  ihue = (ihue + thisstep) % 256;

  ledsA.setPixelColor(idex, ledsA.ColorHSV(ihue, thissat, 255));
  ledsB.setPixelColor(idex, ledsB.ColorHSV(ihue, thissat, 255));
  ledsA.show();
  ledsB.show();
  delay(thisdelay);
}

void ems_lightsSTROBE() {                  // полицейская мигалка
  int TOP_INDEX = int(NUM_LEDS / 2);
  int thishue = 0;
  int thathue = (thishue + 160) % 255;
  
  for (int x = 0; x < 5; x++) {
    for (int i = 0; i < TOP_INDEX; i++) {
      ledsA.setPixelColor(i, ledsA.Color(160, 255, 255));
      ledsB.setPixelColor(i, ledsB.Color(160, 255, 255));
    }
    ledsA.show();
    ledsB.show();
    delay(thisdelay);
    
    one_color_all(0, 0, 0);
    ledsA.show();
    ledsB.show();
    delay(thisdelay);
  }
  
  for (int x = 0; x < 5; x++) {
    for (int i = TOP_INDEX; i < NUM_LEDS; i++) {
      ledsA.setPixelColor(i, ledsA.Color(0, 255, 255));
      ledsB.setPixelColor(i, ledsB.Color(0, 255, 255));
    }
    ledsA.show();
    ledsB.show();
    delay(thisdelay);
    
    one_color_all(0, 0, 0);
    ledsA.show();
    ledsB.show();
    delay(thisdelay);
  }
}

void OutsideToCenterA(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) //убрать
{
    ledsA.setBrightness(Brgh);
    ledsB.setBrightness(Brgh);
    long long numberB = strtoll( &colorB[1], NULL, 16);
    long long rB = numberB >> 16;
    long long gB = numberB >> 8 & 0xFF;
    long long bB = numberB & 0xFF;
  for(int i = 0; i<=((NUM_LEDS-EyeSize)/2); i++) 
  {
    one_color_all(0, 0, 0);
    ledsA.fill(ledsA.Color(red / 10, green / 10, blue / 10), i, EyeSize + 2);
    ledsA.fill(ledsA.Color(red, green, blue), i + 1, EyeSize);
    ledsA.fill(ledsA.Color(red / 10, green / 10, blue / 10), NUM_LEDS - i - EyeSize - 1, EyeSize + 2);

  
  for (int y = 0; y < 30; y++) {
      if (led_arrayB[y] == 0) {
          ledsB.setPixelColor(y, ledsB.Color(0, 0, 0));
      } else {
          ledsB.setPixelColor(y, ledsB.Color(rB, gB, bB));
      }
  } 
    ledsA.show();
    ledsB.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}
void OutsideToCenterB(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) //убрать
{
    ledsA.setBrightness(Brgh);
    ledsB.setBrightness(Brgh);
    long long numberA = strtoll( &colorA[1], NULL, 16);
    long long rA = numberA >> 16;
    long long gA = numberA >> 8 & 0xFF;
    long long bA = numberA & 0xFF;
  for(int i = 0; i<=((NUM_LEDS-EyeSize)/2); i++) 
  {
    one_color_all(0, 0, 0);
    ledsB.fill(ledsB.Color(red / 10, green / 10, blue / 10), i, EyeSize + 2);
    ledsB.fill(ledsB.Color(red, green, blue), i + 1, EyeSize);
    ledsB.fill(ledsB.Color(red / 10, green / 10, blue / 10), NUM_LEDS - i - EyeSize - 1, EyeSize + 2);

  
  for (int y = 0; y < 30; y++) {
      if (led_arrayA[y] == 0) {
          ledsA.setPixelColor(y, ledsA.Color(0, 0, 0));
      } else {
          ledsA.setPixelColor(y, ledsA.Color(rA, gA, bA));
      }
  } 
    ledsA.show();
    ledsB.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}
void OutsideToCenterAvar(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) //Аварийка эффекты
{
  ledsA.setBrightness(Brgh);
  ledsB.setBrightness(Brgh);
  for(int i = 0; i<=((NUM_LEDS-EyeSize)/2); i++) 
  {
    one_color_all(0, 0, 0);
    ledsB.fill(ledsB.Color(red / 10, green / 10, blue / 10), i, EyeSize + 2);
    ledsA.fill(ledsA.Color(red / 10, green / 10, blue / 10), i, EyeSize + 2);
    ledsB.fill(ledsB.Color(red, green, blue), i + 1, EyeSize);
    ledsA.fill(ledsA.Color(red, green, blue), i + 1, EyeSize);
    ledsB.fill(ledsB.Color(red / 10, green / 10, blue / 10), NUM_LEDS - i - EyeSize - 1, EyeSize + 2);
    ledsA.fill(ledsA.Color(red / 10, green / 10, blue / 10), NUM_LEDS - i - EyeSize - 1, EyeSize + 2);
    ledsB.fill(ledsB.Color(red, green, blue), NUM_LEDS - i - EyeSize, EyeSize);
    ledsA.fill(ledsA.Color(red, green, blue), NUM_LEDS - i - EyeSize, EyeSize);

    ledsA.show();
    ledsB.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}
void OutsideToCenterAoff(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay)  //Левый поворотник эффекты
{
    ledsA.setBrightness(Brgh);
  for(int i = 0; i<=((NUM_LEDS-EyeSize)/2); i++) 
  {
    one_color_all(0, 0, 0);
    ledsA.fill(ledsA.Color(red / 10, green / 10, blue / 10), i, EyeSize + 2);
    ledsA.fill(ledsA.Color(red, green, blue), i + 1, EyeSize);
    ledsA.fill(ledsA.Color(red / 10, green / 10, blue / 10), NUM_LEDS - i - EyeSize - 1, EyeSize + 2);
    ledsA.fill(ledsA.Color(red, green, blue), NUM_LEDS - i - EyeSize, EyeSize);

    ledsA.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}
void OutsideToCenterBoff(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) //Правый поворотник эффекты
{
      ledsB.setBrightness(Brgh);
    
  for(int i = 0; i<=((NUM_LEDS-EyeSize)/2); i++) 
  {
    one_color_all(0, 0, 0);
    ledsB.fill(ledsB.Color(red / 10, green / 10, blue / 10), i, EyeSize + 2);
    ledsB.fill(ledsB.Color(red, green, blue), i + 1, EyeSize);
    ledsB.fill(ledsB.Color(red / 10, green / 10, blue / 10), NUM_LEDS - i - EyeSize - 1, EyeSize + 2);
    ledsB.fill(ledsB.Color(red, green, blue), NUM_LEDS - i - EyeSize, EyeSize);

    ledsB.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}
void effects(){
    //Serial.println(effects_led);
    switch (effects_led)
    {
        case 1: led_default(); break;//Обычные габариты            
        case 2: rainbow_loop(); break;            // крутящаяся радуга
        case 3: ems_lightsSTROBE(); break;        // полицейская мигалка
        case 4: OutsideToCenterAoff(0xff, 69, 0, 4, 80, 100); break; //Левый поворотник
        case 5: OutsideToCenterBoff(0xff, 69, 0, 4, 80, 100); break; //Правый поворотник
        case 6: OutsideToCenterAvar(0xff, 69, 0, 4, 80, 100); break; //Аварийка
        case 0:
            one_color_all(0, 0, 0); //Выключить все светодиоды
            ledsA.show();
            ledsB.show();
            break;
    }
}