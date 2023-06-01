    int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
    int ihue = 0;                //-HUE (0-255)
    int thisdelay = 20;          //-FX LOOPS DELAY VAR
    int thisstep = 10;           //-FX LOOPS DELAY VAR
    int thishue = 0;             //-FX LOOPS DELAY VAR
    int thissat = 255;           //-FX LOOPS DELAY VAR

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    ledsA.setPixelColor(i, ledsA.Color(cred, cgrn, cblu));
    ledsB.setPixelColor(i, ledsB.Color(cred, cgrn, cblu));
  }
}
void one_color_allA(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    ledsA.setPixelColor(i, ledsA.Color(cred, cgrn, cblu));
  }
}
void one_color_allB(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    ledsB.setPixelColor(i, ledsB.Color(cred, cgrn, cblu));
  }
}
void one_color_avar() {       //аварийка 
ledsA.setBrightness(Brgh);
ledsB.setBrightness(Brgh);
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsA.setPixelColor(i, ledsA.Color(255, 69, 0));
    ledsB.setPixelColor(i, ledsB.Color(255, 69, 0));
  }
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);
  one_color_all(0, 0, 0);
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);
}
void one_color_A() {       // Весь цвет светодиода А
ledsA.setBrightness(Brgh);
ledsB.setBrightness(Brgh);
    long long numberB = strtoll( &colorB[1], NULL, 16);
    long long rB = numberB >> 16;
    long long gB = numberB >> 8 & 0xFF;
    long long bB = numberB & 0xFF;
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsA.setPixelColor(i, ledsA.Color(255, 69, 0));
  }
  for (int y = 0; y < NUM_LEDS; y++) {
    ledsB.setPixelColor(y, led_arrayB[y] == 0 ? ledsB.Color(0, 0, 0) : ledsB.Color(rB, gB, bB));
  }
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);

  one_color_allA(0, 0, 0);
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);
}

void one_color_B() {       // Весь цвет светодиода B
ledsA.setBrightness(Brgh);
ledsB.setBrightness(Brgh);
    long long numberA = strtoll( &colorA[1], NULL, 16);
    long long rA = numberA >> 16;
    long long gA = numberA >> 8 & 0xFF;
    long long bA = numberA & 0xFF;
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsB.setPixelColor(i, ledsB.Color(255, 69, 0));
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
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);
}
void one_color_Aoff() {       // Выключены габариты светодиода А
 ledsA.setBrightness(Brgh);
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsA.setPixelColor(i, ledsA.Color(255, 69, 0));
  }
  ledsA.show(); // Отобразить изменения на ленте ledsA
  delay(320);

  one_color_allA(0, 0, 0);
  ledsA.show(); // Отобразить изменения на ленте ledsA
  delay(320);
}
void one_color_Boff() {       // Выключены габариты светодиода B
ledsB.setBrightness(Brgh);
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    //0xff, 69, 0, 4, 80, 100
    ledsB.setPixelColor(i, ledsB.Color(255, 69, 0));
  }
 ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);

  one_color_allB(0, 0, 0);
  ledsB.show(); // Отобразить изменения на ленте ledsB
  delay(320);
}

void led_default(){
    // Get rid of '#' and convert it to integer
  long long numberA = strtoll( &colorA[1], NULL, 16);
  long long numberB = strtoll( &colorB[1], NULL, 16);
  long long rA = numberA >> 16;
  long long gA = numberA >> 8 & 0xFF;
  long long bA = numberA & 0xFF;
  
  long long rB = numberB >> 16;
  long long gB = numberB >> 8 & 0xFF;
  long long bB = numberB & 0xFF;
  ledsA.setBrightness(Brgh);
  ledsB.setBrightness(Brgh);
  //Serial.print(led_arrayA[0]); Serial.print(" - ");Serial.print(led_arrayA[1]);Serial.println();
  //delay(400); //задержка для поворотов
  for (int x = 0; x < 30; x++) {
      if (led_arrayA[x] == 0) {
           ledsA.setPixelColor(x, ledsA.Color(0, 0, 0));
      } else {
          ledsA.setPixelColor(x, ledsA.Color(rA, gA, bA));
      }
  }
  for (int y = 0; y < 30; y++) {
      if (led_arrayB[y] == 0) {
          ledsB.setPixelColor(y, ledsB.Color(0, 0, 0));
      } else {
          ledsB.setPixelColor(y, ledsB.Color(rB, gB, bB));
      }
  }
  
  ledsA.show(); // Отобразить изменения на ленте ledsA
  ledsB.show(); // Отобразить изменения на ленте ledsB
}
void rainbow_loop() {                        //-m3-LOOP HSV RAINBOW

  idex = (idex + 1) % NUM_LEDS;
  ihue = (ihue + thisstep) % 256;

  ledsA.setPixelColor(idex, ledsA.ColorHSV(ihue, thissat, 255));
  ledsB.setPixelColor(idex, ledsB.ColorHSV(ihue, thissat, 255));
  ledsA.show();
  ledsB.show();
  delay(thisdelay);
}

void ems_lightsSTROBE() {                  //-m26-EMERGENCY LIGHTS (STROBE LEFT/RIGHT)
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

void OutsideToCenterA(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
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
void OutsideToCenterB(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
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
void OutsideToCenterAvar(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
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
void OutsideToCenterAoff(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
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
void OutsideToCenterBoff(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
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
        case 1: 
            
            led_default();
            break;
        case 2: rainbow_loop(); break;            // крутящаяся радуга
        case 3: ems_lightsSTROBE(); break;        // полицейская мигалка
        case 4: OutsideToCenterAoff(0xff, 69, 0, 4, 80, 100); break;
        case 5: OutsideToCenterBoff(0xff, 69, 0, 4, 80, 100); break;
        case 6: OutsideToCenterAvar(0xff, 69, 0, 4, 80, 100); break;
        case 0:
            one_color_all(0, 0, 0);
            ledsA.show();
            ledsB.show();
            break;
    }
}