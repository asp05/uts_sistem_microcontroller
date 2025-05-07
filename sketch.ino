#include <LiquidCrystal_I2C.h>
const int pirPin = 2;               // Pin sensor PIR
const int ledPin = 3;                // Pin LED
const int buzzerPin = 4;     
LiquidCrystal_I2C lcd(0x27, 16, 2);        // Pin buzzer (opsional)

void setup() {
  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistem Rumah");
  lcd.setCursor(0, 1);
  lcd.print("  Siap...");
  
  // Set pin mode
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  delay(2000); // Waktu tunggu awal
}

void loop() {
  int pirState = digitalRead(pirPin); // Baca sensor PIR
  
  if (pirState == HIGH) {
    // Gerakan terdeteksi
    digitalWrite(ledPin, HIGH);     // Nyalakan LED
    digitalWrite(buzzerPin, HIGH);  // Nyalakan buzzer (opsional)
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gerakan Terdeteksi!");
    lcd.setCursor(0, 1);
    lcd.print("Lampu: NYALA");
    
    delay(100); // Buzzer berbunyi sebentar
    digitalWrite(buzzerPin, LOW); // Matikan buzzer
  } else {
    // Tidak ada gerakan
    digitalWrite(ledPin, LOW);      // Matikan LED
    digitalWrite(buzzerPin, LOW);   // Matikan buzzer
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tidak Ada Gerakan");
    lcd.setCursor(0, 1);
    lcd.print("Lampu: MATI");
  }
  
  delay(500); // Delay untuk stabilitas
}
