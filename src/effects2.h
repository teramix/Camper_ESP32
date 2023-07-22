  
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
  //ledsA.setBrightness(Brgh);
  //ledsB.setBrightness(Brgh);
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
  //int thishue = 0;
  //int thathue = (thishue + 160) % 255;
  
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