unsigned long PreviousTime=0;
const unsigned long interval=1500;
unsigned long timer;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <DHT.h>;
#define DHTPIN 8
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float t;
float h;
void setup() {
 lcd.init();
 lcd.backlight();
 dht.begin();
 pinMode(7, OUTPUT);
 pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite(6, HIGH);
    h = dht.readHumidity();
    t = dht.readTemperature();
  timer=millis();
  if(timer-PreviousTime>=interval){
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(t-9.0);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("Humid:");
    lcd.print(h-14);
    lcd.print(" %");
    PreviousTime=timer;
  }
    if(t-9.0>20) digitalWrite(7, LOW);
    else digitalWrite(7, HIGH);
    if(t-9.0<17) digitalWrite(6, LOW);
    else digitalWrite(6, HIGH);
 }
