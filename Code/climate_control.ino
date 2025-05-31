#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

const int tempSensorPin = A3;
const int fanPin = 6;
const int heaterPin = 7;
int desiredTemp = 25; 

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {8, 9, 10, 13};
byte colPins[COLS] = {A0, A1, A2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int tempBuffer = 0;
bool inputActive = false; 

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(heaterPin, OUTPUT);

  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  Serial.begin(9600); 
}

void loop() {
  int currentTemp1 = analogRead(tempSensorPin);
  int currentTemp = map(currentTemp1, 0, 1023, 0, 50);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(currentTemp);
  lcd.print("C    ");

  if (inputActive) {
    char key = keypad.getKey();
    
    if (key) {
      if (isDigit(key)) {
        tempBuffer = tempBuffer * 10 + (key - '0'); 
        if (tempBuffer > 50) tempBuffer = 50;       
        lcd.setCursor(0, 1);
        lcd.print("Enter Temp: ");
        lcd.print(tempBuffer);
        lcd.print("C    ");
      } else if (key == '#') {
        desiredTemp = tempBuffer; 
        tempBuffer = 0;           
        inputActive = false;      
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp Set to: ");
        lcd.print(desiredTemp);
        lcd.print("C    ");
        delay(2000); 
        lcd.clear();
      } else if (key == '*') {
        tempBuffer = 0; 
        lcd.setCursor(0, 1);
        lcd.print("Input Cleared ");
        delay(1000); 
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter Temp: ");
      }
    }
  } else {

    int currentTemp1 = analogRead(tempSensorPin);
    int currentTemp = map(currentTemp1, 0, 1023, 0, 50);

    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(currentTemp);
    lcd.print("C    "); 


    if (currentTemp < desiredTemp) {
      digitalWrite(heaterPin, HIGH);
      analogWrite(fanPin, 0);
      lcd.setCursor(0, 1);
      lcd.print("Heating...     ");
    } else if (currentTemp > desiredTemp) {
      digitalWrite(heaterPin, LOW);
      int fanSpeed = map(currentTemp - desiredTemp, 1, 10, 100, 255);
      analogWrite(fanPin, fanSpeed);


      lcd.setCursor(0, 1);
      lcd.print("Cooling: ");
      lcd.print("Fan ");
      lcd.print(fanSpeed);
      lcd.print("    ");
    } else {
      digitalWrite(heaterPin, LOW);
      analogWrite(fanPin, 0);
      lcd.setCursor(0, 1);
      lcd.print("Temp Stable    ");
    }
  }

  if (!inputActive) {
    char key = keypad.getKey();
    
    if (key == '*') {
      inputActive = true;
      tempBuffer = 0;     
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Temp: ");
    }
  }

  delay(500);
}
