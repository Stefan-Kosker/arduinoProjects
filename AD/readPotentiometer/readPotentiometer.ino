#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int sensorPin = A0;
int sensorValue = 0;
double maxVoltageValue = 5.0;
double voltage = 0.0;

void setup() {
  lcd.begin(20,4);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  voltage = ((double)sensorValue / 1023.0) * maxVoltageValue;
  lcd.setCursor(0,0); //Ab hier kann das I2C LCD Modul genau wie das einfache LCD Modul programmiert werden.
  lcd.print("Spannung: ");
  lcd.print(voltage);
  lcd.print(" V");
  delay(100);
}

