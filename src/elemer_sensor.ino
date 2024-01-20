/*
  Подключение термометра сопротивления Элемер ТС-1088 к Arduino Nano
  Автор: Степанов А.А.
  Дата последнего изменения: 16.01.2024
  Эта программа предназначена для сопряжения платы Arduino с термометром
  сопротивления Элемер ТС-1088. Сопротивление термометра измеряется на основе
  температуры окружающей среды, а затем преобразуется в градусы Цельсия
*/

#include <LiquidCrystal_I2C.h>

#define ANALOG_PIN A3                   // Инициализация аналогового порта А3

LiquidCrystal_I2C lcd(0x27, 16, 2);     // Инициализация ЖК-дисплея

int Vin = 5;                            // Входное напряжение (+5В)
float Vout = 0;                         // Выходное напряжение (Неизвестно)

float R1 = 380;                         // Значение сопротивления известного резистора
float Rout = 0;                         // Значение сопротивления с датчика термометра
float Tout = 0;                         // Значение температуры с датчика термометра

int temp_data = 0;                      // Чтение значений с аналогового порта А3

float buffer = 0;                       // Переменная буфер

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  temp_data = analogRead(ANALOG_PIN);    // Чтение данных с аналогового порта А3

  if (temp_data)
  {
    buffer = temp_data * Vin;

    Vout = (temp_data * Vin) / 1024.0;

    buffer = Vout / (Vin - Vout);

    Rout = (R1 * buffer) - 5;


    // Расчет температуры согласно зависимости температуры и сопротивления для НСХ 50М
    if (Rout > 39.30 && Rout < 41.44)
    {
      Tout = -50;
    } else if (Rout >= 41.44 && Rout < 43.58)
    {
      Tout = -40;
    } else if (Rout >= 43.58 && Rout < 45.72)
    {
      Tout = -30;
    } else if (Rout >= 45.72 && Rout < 47.86)
    {
      Tout = -20;
    } else if (Rout >= 47.86 && Rout < 50.00)
    {
      Tout = -10;
    } else if (Rout >= 50.00 && Rout < 52.14)
    {
      Tout = 0;
    } else if (Rout >= 52.14 && Rout < 54.28)
    {
      Tout = 10;
    } else if (Rout >= 54.28 && Rout < 56.42)
    {
      Tout = 20;
    } else if (Rout >= 56.42 && Rout < 58.56)
    {
      Tout = 30;
    } else if (Rout >= 58.56 && Rout < 60.70)
    {
      Tout = 40;
    } else if (Rout >= 60.70 && Rout < 62.84)
    {
      Tout = 50;
    } else if (Rout >= 62.84 && Rout < 64.98)
    {
      Tout = 60;
    } else if (Rout >= 64.98 && Rout < 67.12)
    {
      Tout = 70;
    } else if (Rout >= 67.12 && Rout < 69.26)
    {
      Tout = 80;
    } else if (Rout >= 69.26 && Rout < 71.40)
    {
      Tout = 90;
    } else if (Rout >= 71.40 && Rout < 73.54)
    {
      Tout = 100;
    } else if (Rout >= 73.54 && Rout < 75.68)
    {
      Tout = 110;
    } else if (Rout >= 75.68 && Rout < 77.82)
    {
      Tout = 120;
    } else if (Rout >= 77.82 && Rout < 79.96)
    {
      Tout = 130;
    } else if (Rout >= 79.96 && Rout < 82.10)
    {
      Tout = 140;
    } else if (Rout >= 82.10 && Rout < 84.24)
    {
      Tout = 150;
    } else if (Rout >= 84.24 && Rout < 86.38)
    {
      Tout = 160;
    } else if (Rout >= 86.38 && Rout < 88.52)
    {
      Tout = 170;
    } else if (Rout >= 88.52 && Rout < 90)
    {
      Tout = 180;
    }

    lcd.clear();
    
    lcd.setCursor(0, 0);
    
    lcd.print("Rout = ");
    lcd.print(Rout);
    
    lcd.setCursor(0, 1);
    
    lcd.print("Temp = ");
    lcd.print(Tout);
    lcd.print(char(223));

    delay(2000);                         // Обновление значений на ЖК-дисплее происходит с периодичностью в две секунды
  }
}
