#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

const int seatBeltPin = A5; 
const int doorLockPin = A4; 
const int motorPin = 6;

void setup() {
  pinMode(seatBeltPin, INPUT_PULLUP); 
  pinMode(doorLockPin, INPUT_PULLUP); 
  pinMode(motorPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Safety Check...");
  
  Serial.begin(9600);
}

void loop() {
  int seatBeltStatus = digitalRead(seatBeltPin);
  int doorLockStatus = digitalRead(doorLockPin);



  if (seatBeltStatus == HIGH && doorLockStatus == HIGH) {
    digitalWrite(motorPin, HIGH); 
    lcd.setCursor(0, 1);
    lcd.print("Ready to Go!   ");
  } else {
    digitalWrite(motorPin, LOW); 
    lcd.setCursor(0, 1);
    if (seatBeltStatus == LOW) {
      lcd.print("Fasten Belt!   ");
    } else if (doorLockStatus == LOW) {
      lcd.print("Lock Doors!    ");
    }
  }

  delay(500);
}
