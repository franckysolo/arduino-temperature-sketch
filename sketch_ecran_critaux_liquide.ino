#include <LiquidCrystal.h>

#define LCD_RS 7
#define LCD_E  8
#define LCD_D4 9
#define LCD_D5 10
#define LCD_D6 11
#define LCD_D7 12

LiquidCrystal lcd(LCD_RS,LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

const int sensorPin = A0;

// degree centigrade
byte newChar1[8] = {
  B01000,
  B10100,
  B01000,
  B00011,
  B00100,
  B00100,
  B00011,
  B00000
};

void setup() {
  // On ouvre un port serie
  Serial.begin(9600);
  // initalisation
  lcd.begin(16, 2);
  // Affichage
  lcd.print("Temperature");
}

void loop() {
  // on recuppère la valeur du capteur de température TMP36
  int sensorVal = analogRead(sensorPin);
  Serial.print("Valeur du capteur: ");
  Serial.println(sensorVal);
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print("Voltage: ");
  Serial.println(voltage);
  float temperature = (voltage - 0.5) * 100;
  Serial.print("Temperature: ");
  Serial.println(temperature);
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.createChar(0, newChar1);
  lcd.setCursor(5, 1);
  for(int n = 0; n < 1; n++)
  {
    lcd.write(n);
  }
  lcd.setCursor(7, 1);
  delay(1000);
}
