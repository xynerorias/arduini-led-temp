#include <TinyDHT.h>
#include <LiquidCrystal_I2C.h>

#define CELCIUS 0
#define LCD_ADDRESS 0x27

DHT dht(2, DHT11);
LiquidCrystal_I2C liquid(LCD_ADDRESS,16,2);

void setup() {

  dht.begin();
  liquid.init();
  liquid.setBacklight(HIGH);
  
}


void loop() {

  int16_t temp = dht.readTemperature(CELCIUS);
  int8_t hum = dht.readHumidity();

  liquid.setCursor(0,0);
  liquid.print("Temperature ");
  liquid.print(temp);
  liquid.print((char)0xdf);
  liquid.print("C");

  liquid.setCursor(0,1);
  liquid.print("Humidite ");
  liquid.print(hum);
  liquid.print("%");
  
  delay(5000);

}
