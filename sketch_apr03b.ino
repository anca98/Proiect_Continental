#include <Wire.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F,16,2);  
/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
//valoarea analog a potentiometrului(valoarea citita de pe placa , nemodificata)
int  potentiometru;
//valoarea analog a temperaturii(valoarea citita de pe placa , nemodificata)
float tempAnalog;


void setup() {
  lcd.begin();
    lcd.backlight();
  //lcd.print("Hello, world!");
  
  Serial.begin(9600);
  // seteaza pinul 6 al tranzistorului ca si output
  pinMode(6, OUTPUT);
  

                     

  

}

void loop() 
{
  //formula care converteste valoarea potentiometrul de la intervalul( 0 , 1023) la (0, 29)
  //analogRead citeste valoarea potentiometrului pe care o da placa
potentiometru = analogRead (A5)/35;
//analogRead citeste valoarea temperaturii pe care o da placa
tempAnalog = analogRead (A4);
// formula extrasa din documentatia senzorului de temperatura care transforma valoarea analog in grade Celsius
float tempGrade =tempAnalog * (-0.46) + 193;


//daca temperatura citita de senzor este mai mica decat temperatura daca de utilizator din potentiometru atunci 
if(tempGrade<potentiometru)
{// se PORNESTE becul
  digitalWrite(6,HIGH);
}
//daca temperatura senzorului este aceeasi cu temperatura potentiometrului se OPRESTE becul 
else digitalWrite(6,LOW);

  


Serial.println (tempGrade);
lcd.print (tempGrade);
lcd.print (" Grade");

lcd.print (potentiometru);
delay (1000);
lcd.clear();

Serial.println (potentiometru);

delay (500);
lcd.clear();



delay(500);



}
