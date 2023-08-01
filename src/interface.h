

// глобальные переменные для работы с ними в программе
//int dht_int; // интервал замера температуры и влажности в секундах 
//int ds_int; // интервал замера ds18b20 в секундах 
//int mqtt_int; // интервал отправки данных по MQTT в секундах 
//float tem; // тут храним температуру
//float hum; // влажность
String colorA;
String colorB;
String colorA2; // цвет центра
String colorB2; // цвет центра
String color_rep; // цвет поворотников
int Brgh;
int Brgh2; //яркость центрального светодиода ПОКА не используется
int effects_led;
//String chkA{1,3};
//String chkA2;
boolean led_arrayA[31];
boolean led_arrayB[31];


void parameters(){
// создаем параметры для нашего проекта
  jee.var("wifi", "AP"); // режим работы WiFi по умолчанию ("STA" или "AP")  (параметр в энергонезависимой памяти)
  jee.var("ssid", "wifi_scpp"); // имя точки доступа к которой подключаемся (параметр в энергонезависимой памяти)
  jee.var("pass", "Scpp2020"); // пароль точки доступа к которой подключаемся (параметр в энергонезависимой памяти)
  jee.var("ap_ssid", "Camper");
  jee.var("ap_pass", "123456789");

  
  jee.var("color_led_A", "#baffff");
  jee.var("color_led_B", "#baffff");
  jee.var("color_led_A2", "#baffff");
  jee.var("color_led_B2", "#baffff");
  jee.var("color_led_rep", "#ff4f00");
  jee.var("Brgh2", "50");
  jee.var("Brgh", "50");
  jee.var("cnt1", "1");

  jee.var("chkA1", "true");
  jee.var("chkA2", "true");
  jee.var("chkA3", "true");
  jee.var("chkA4", "true");
  jee.var("chkA5", "true");
  jee.var("chkA6", "true");
  jee.var("chkA7", "true");
  jee.var("chkA8", "true");
  jee.var("chkA9", "true");
  jee.var("chkA10", "true");
  jee.var("chkA11", "true");
  jee.var("chkA12", "true");
  jee.var("chkA13", "true");
  jee.var("chkA14", "true");
  jee.var("chkA15", "true");
  jee.var("chkA16", "true");
  jee.var("chkA17", "true");
  jee.var("chkA18", "true");
  jee.var("chkA19", "true");
  jee.var("chkA20", "true");
  jee.var("chkA21", "true");
  jee.var("chkA22", "true");
  jee.var("chkA23", "true");
  jee.var("chkA24", "true");
  jee.var("chkA25", "true");
  jee.var("chkA26", "true");
  jee.var("chkA27", "true");
  jee.var("chkA28", "true");
  jee.var("chkA29", "true");
  jee.var("chkA30", "true");
  jee.var("chkA31", "true");

  jee.var("chkB1", "true");
  jee.var("chkB2", "true");
  jee.var("chkB3", "true");
  jee.var("chkB4", "true");
  jee.var("chkB5", "true");
  jee.var("chkB6", "true");
  jee.var("chkB7", "true");
  jee.var("chkB8", "true");
  jee.var("chkB9", "true");
  jee.var("chkB10", "true");
  jee.var("chkB11", "true");
  jee.var("chkB12", "true");
  jee.var("chkB13", "true");
  jee.var("chkB14", "true");
  jee.var("chkB15", "true");
  jee.var("chkB16", "true");
  jee.var("chkB17", "true");
  jee.var("chkB18", "true");
  jee.var("chkB19", "true");
  jee.var("chkB20", "true");
  jee.var("chkB21", "true");
  jee.var("chkB22", "true");
  jee.var("chkB23", "true");
  jee.var("chkB24", "true");
  jee.var("chkB25", "true");
  jee.var("chkB26", "true");
  jee.var("chkB27", "true");
  jee.var("chkB28", "true");
  jee.var("chkB29", "true");
  jee.var("chkB30", "true");
  jee.var("chkB31", "true");
  
}

void update(){ // функция выполняется после ввода данных в веб интерфейсе. получение параметров из веб интерфейса в переменные
  // получаем данные в переменную в ОЗУ для дальнейшей работы
  //dht_int = jee.param("dht_int").toInt();
  //ds_int = jee.param("ds_int").toInt();
  //mqtt_int = jee.param("mqtt_int").toInt();
   colorA = String(jee.param("color_led_A"));
   colorB = String(jee.param("color_led_B")); 
   color_rep = String(jee.param("color_led_rep"));   
   colorA2 = String(jee.param("color_led_A2")); // Центр
   colorB2 = String(jee.param("color_led_B2")); // Центр
   Brgh = jee.param("Brgh").toInt();
   Brgh2 = jee.param("Brgh2").toInt();
   effects_led = jee.param("cnt1").toInt();
   //Чек светодиодов
  //led_arrayA[0] = boolean(jee.param("chkA1"));
  //led_arrayA[1] = boolean(jee.param("chkA2"));
  if (String(jee.param("chkA1")) == "true") { led_arrayA[0] = true; }else { led_arrayA[0] = false;}
  if (String(jee.param("chkA2")) == "true") { led_arrayA[1] = true; }else { led_arrayA[1] = false;}
  if (String(jee.param("chkA3")) == "true") { led_arrayA[2] = true; }else { led_arrayA[2] = false;}
  if (String(jee.param("chkA4")) == "true") { led_arrayA[3] = true; }else { led_arrayA[3] = false;}
  if (String(jee.param("chkA5")) == "true") { led_arrayA[4] = true; }else { led_arrayA[4] = false;}
  if (String(jee.param("chkA6")) == "true") { led_arrayA[5] = true; }else { led_arrayA[5] = false;}
  if (String(jee.param("chkA7")) == "true") { led_arrayA[6] = true; }else { led_arrayA[6] = false;}
  if (String(jee.param("chkA8")) == "true") { led_arrayA[7] = true; }else { led_arrayA[7] = false;}
  if (String(jee.param("chkA9")) == "true") { led_arrayA[8] = true; }else { led_arrayA[8] = false;}
  if (String(jee.param("chkA10")) == "true") { led_arrayA[9] = true; }else { led_arrayA[9] = false;}
  if (String(jee.param("chkA11")) == "true") { led_arrayA[10] = true; }else { led_arrayA[10] = false;}
  if (String(jee.param("chkA12")) == "true") { led_arrayA[11] = true; }else { led_arrayA[11] = false;}
  if (String(jee.param("chkA13")) == "true") { led_arrayA[12] = true; }else { led_arrayA[12] = false;}
  if (String(jee.param("chkA14")) == "true") { led_arrayA[13] = true; }else { led_arrayA[13] = false;}
  if (String(jee.param("chkA15")) == "true") { led_arrayA[14] = true; }else { led_arrayA[14] = false;}
  if (String(jee.param("chkA16")) == "true") { led_arrayA[15] = true; }else { led_arrayA[15] = false;}
  if (String(jee.param("chkA17")) == "true") { led_arrayA[16] = true; }else { led_arrayA[16] = false;}
  if (String(jee.param("chkA18")) == "true") { led_arrayA[17] = true; }else { led_arrayA[17] = false;}
  if (String(jee.param("chkA19")) == "true") { led_arrayA[18] = true; }else { led_arrayA[18] = false;}
  if (String(jee.param("chkA20")) == "true") { led_arrayA[19] = true; }else { led_arrayA[19] = false;}
  if (String(jee.param("chkA21")) == "true") { led_arrayA[20] = true; }else { led_arrayA[20] = false;}
  if (String(jee.param("chkA22")) == "true") { led_arrayA[21] = true; }else { led_arrayA[21] = false;}
  if (String(jee.param("chkA23")) == "true") { led_arrayA[22] = true; }else { led_arrayA[22] = false;}
  if (String(jee.param("chkA24")) == "true") { led_arrayA[23] = true; }else { led_arrayA[23] = false;}
  if (String(jee.param("chkA25")) == "true") { led_arrayA[24] = true; }else { led_arrayA[24] = false;}
  if (String(jee.param("chkA26")) == "true") { led_arrayA[25] = true; }else { led_arrayA[25] = false;}
  if (String(jee.param("chkA27")) == "true") { led_arrayA[26] = true; }else { led_arrayA[26] = false;}
  if (String(jee.param("chkA28")) == "true") { led_arrayA[27] = true; }else { led_arrayA[27] = false;}
  if (String(jee.param("chkA29")) == "true") { led_arrayA[28] = true; }else { led_arrayA[28] = false;}
  if (String(jee.param("chkA30")) == "true") { led_arrayA[29] = true; }else { led_arrayA[29] = false;}
  if (String(jee.param("chkA31")) == "true") { led_arrayA[30] = true; }else { led_arrayA[30] = false;}
 //// Включен/выключен светодио левой фары
  if (String(jee.param("chkB1")) == "true") { led_arrayB[0] = true; }else { led_arrayB[0] = false;}
  if (String(jee.param("chkB2")) == "true") { led_arrayB[1] = true; }else { led_arrayB[1] = false;}
  if (String(jee.param("chkB3")) == "true") { led_arrayB[2] = true; }else { led_arrayB[2] = false;}
  if (String(jee.param("chkB4")) == "true") { led_arrayB[3] = true; }else { led_arrayB[3] = false;}
  if (String(jee.param("chkB5")) == "true") { led_arrayB[4] = true; }else { led_arrayB[4] = false;}
  if (String(jee.param("chkB6")) == "true") { led_arrayB[5] = true; }else { led_arrayB[5] = false;}
  if (String(jee.param("chkB7")) == "true") { led_arrayB[6] = true; }else { led_arrayB[6] = false;}
  if (String(jee.param("chkB8")) == "true") { led_arrayB[7] = true; }else { led_arrayB[7] = false;}
  if (String(jee.param("chkB9")) == "true") { led_arrayB[8] = true; }else { led_arrayB[8] = false;}
  if (String(jee.param("chkB10")) == "true") { led_arrayB[9] = true; }else { led_arrayB[9] = false;}
  if (String(jee.param("chkB11")) == "true") { led_arrayB[10] = true; }else { led_arrayB[10] = false;}
  if (String(jee.param("chkB12")) == "true") { led_arrayB[11] = true; }else { led_arrayB[11] = false;}
  if (String(jee.param("chkB13")) == "true") { led_arrayB[12] = true; }else { led_arrayB[12] = false;}
  if (String(jee.param("chkB14")) == "true") { led_arrayB[13] = true; }else { led_arrayB[13] = false;}
  if (String(jee.param("chkB15")) == "true") { led_arrayB[14] = true; }else { led_arrayB[14] = false;}
  if (String(jee.param("chkB16")) == "true") { led_arrayB[15] = true; }else { led_arrayB[15] = false;}
  if (String(jee.param("chkB17")) == "true") { led_arrayB[16] = true; }else { led_arrayB[16] = false;}
  if (String(jee.param("chkB18")) == "true") { led_arrayB[17] = true; }else { led_arrayB[17] = false;}
  if (String(jee.param("chkB19")) == "true") { led_arrayB[18] = true; }else { led_arrayB[18] = false;}
  if (String(jee.param("chkB20")) == "true") { led_arrayB[19] = true; }else { led_arrayB[19] = false;}
  if (String(jee.param("chkB21")) == "true") { led_arrayB[20] = true; }else { led_arrayB[20] = false;}
  if (String(jee.param("chkB22")) == "true") { led_arrayB[21] = true; }else { led_arrayB[21] = false;}
  if (String(jee.param("chkB23")) == "true") { led_arrayB[22] = true; }else { led_arrayB[22] = false;}
  if (String(jee.param("chkB24")) == "true") { led_arrayB[23] = true; }else { led_arrayB[23] = false;}
  if (String(jee.param("chkB25")) == "true") { led_arrayB[24] = true; }else { led_arrayB[24] = false;}
  if (String(jee.param("chkB26")) == "true") { led_arrayB[25] = true; }else { led_arrayB[25] = false;}
  if (String(jee.param("chkB27")) == "true") { led_arrayB[26] = true; }else { led_arrayB[26] = false;}
  if (String(jee.param("chkB28")) == "true") { led_arrayB[27] = true; }else { led_arrayB[27] = false;}
  if (String(jee.param("chkB29")) == "true") { led_arrayB[28] = true; }else { led_arrayB[28] = false;}
  if (String(jee.param("chkB30")) == "true") { led_arrayB[29] = true; }else { led_arrayB[29] = false;}
  if (String(jee.param("chkB31")) == "true") { led_arrayB[30] = true; }else { led_arrayB[30] = false;}

}

void interface(){ // функция в которой мф формируем веб интерфейс
  jee.app("Camper"); // название программы (отображается в веб интерфейсе)

  // создаем меню
  jee.menu("Эффекты");
  jee.menu("Настройки фар");
  jee.menu("Светодиоды правой фары");
  jee.menu("Светодиоды левой фары");
  jee.menu("Настройки Wi-Fi");
  jee.menu("Настройка центра");
  // создаем контент для каждого пункта меню

  jee.page(); // разделитель между страницами
  // Страница "Эффектов"
  jee.option("1", "Обычные габариты");
  jee.option("2", "Крутящаяся радуга");
  jee.option("3", "Полицейская мигалка");
  jee.option("4", "Левый поворотник");
  jee.option("5", "Правый поворотник");
  jee.option("6", "Аварийка");
  jee.option("0", "Выключить все светодиоды");
  jee.select("cnt1", "Выбор эффекта");

  jee.page(); // разделитель между страницами
  // Страница "Настройки фар"
  jee.color("color_led_A", "Цвет правой фары");
  jee.color("color_led_B", "Цвет левой фары");
  jee.color("color_led_rep", "Цвет поворотников");
  jee.range("Brgh", 0, 255, 1, "Яркость светодиодов");

  jee.page(); // разделитель между страницами
  // Страница "Светодиоды правой фары"
  jee.checkbox("chkA1", "1 светодиод");
  jee.checkbox("chkA2", "2 светодиод");
  jee.checkbox("chkA3", "3 светодиод");
  jee.checkbox("chkA4", "4 светодиод");
  jee.checkbox("chkA5", "5 светодиод");
  jee.checkbox("chkA6", "6 светодиод");
  jee.checkbox("chkA7", "7 светодиод");
  jee.checkbox("chkA8", "8 светодиод");
  jee.checkbox("chkA9", "9 светодиод");
  jee.checkbox("chkA10", "10 светодиод");
  jee.checkbox("chkA11", "11 светодиод");
  jee.checkbox("chkA12", "12 светодиод");
  jee.checkbox("chkA13", "13 светодиод");
  jee.checkbox("chkA14", "14 светодиод");
  jee.checkbox("chkA15", "15 светодиод");
  jee.checkbox("chkA16", "16 светодиод");
  jee.checkbox("chkA17", "17 светодиод");
  jee.checkbox("chkA18", "18 светодиод");
  jee.checkbox("chkA19", "19 светодиод");
  jee.checkbox("chkA20", "20 светодиод");
  jee.checkbox("chkA21", "21 светодиод");
  jee.checkbox("chkA22", "22 светодиод");
  jee.checkbox("chkA23", "23 светодиод");
  jee.checkbox("chkA24", "24 светодиод");
  jee.checkbox("chkA25", "25 светодиод");
  jee.checkbox("chkA26", "26 светодиод");
  jee.checkbox("chkA27", "27 светодиод");
  jee.checkbox("chkA28", "28 светодиод");
  jee.checkbox("chkA29", "29 светодиод");
  jee.checkbox("chkA30", "30 светодиод");

  jee.page(); // разделитель между страницами
  // Страница "Светодиоды левой фары"
  jee.checkbox("chkB1", "1 светодиод");
  jee.checkbox("chkB2", "2 светодиод");
  jee.checkbox("chkB3", "3 светодиод");
  jee.checkbox("chkB4", "4 светодиод");
  jee.checkbox("chkB5", "5 светодиод");
  jee.checkbox("chkB6", "6 светодиод");
  jee.checkbox("chkB7", "7 светодиод");
  jee.checkbox("chkB8", "8 светодиод");
  jee.checkbox("chkB9", "9 светодиод");
  jee.checkbox("chkB10", "10 светодиод");
  jee.checkbox("chkB11", "11 светодиод");
  jee.checkbox("chkB12", "12 светодиод");
  jee.checkbox("chkB13", "13 светодиод");
  jee.checkbox("chkB14", "14 светодиод");
  jee.checkbox("chkB15", "15 светодиод");
  jee.checkbox("chkB16", "16 светодиод");
  jee.checkbox("chkB17", "17 светодиод");
  jee.checkbox("chkB18", "18 светодиод");
  jee.checkbox("chkB19", "19 светодиод");
  jee.checkbox("chkB20", "20 светодиод");
  jee.checkbox("chkB21", "21 светодиод");
  jee.checkbox("chkB22", "22 светодиод");
  jee.checkbox("chkB23", "23 светодиод");
  jee.checkbox("chkB24", "24 светодиод");
  jee.checkbox("chkB25", "25 светодиод");
  jee.checkbox("chkB26", "26 светодиод");
  jee.checkbox("chkB27", "27 светодиод");
  jee.checkbox("chkB28", "28 светодиод");
  jee.checkbox("chkB29", "29 светодиод");
  jee.checkbox("chkB30", "30 светодиод");

  jee.page(); // разделитель между страницами
  // Страница "Настройки WiFi"
  jee.formWifi(); // форма настроек Wi-Fi
  jee.page(); // разделитель между страницами
  // Страница настройки центра фар
  jee.checkbox("chkA31", "31 левый ");
  jee.checkbox("chkB31", "31 правый");
  jee.color("color_led_A2", "Цвет левой");
  jee.color("color_led_B2", "Цвет правой");
  jee.range("Brgh2", 0, 255, 1, "Яркость центра");

  jee.page(); // разделитель между страницами

}