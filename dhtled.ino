#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int DHT11_pin=2;
dht11 DHT11_sensor;

#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
}
void loop() {
   int chk = DHT11_sensor.read(DHT11_pin);
  lcd.setCursor(6, 0);
  lcd.print(DHT11_sensor.temperature);
     lcd.print(" Celsius");
  lcd.setCursor(6, 1);
  lcd.print(DHT11_sensor.humidity);
       lcd.print(" %");
  delay(2000);

}
