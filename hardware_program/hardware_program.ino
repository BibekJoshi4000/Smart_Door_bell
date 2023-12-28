#include <LiquidCrystal.h>


#include <IRremote.h>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

const int ir = 3;
const int pir = 5;
const int photo = A1;
const int intruder_light = 8;
const int night_light = 9;
const int button = 7;
const int buzzer = 6;
unsigned int value;

LiquidCrystal lcd(1,2,10,11,12,13);

IRrecv irrecv(ir);
decode_results results;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void setup()
{
  irrecv.enableIRIn();
  lcd.begin(16,2);
  
  pinMode(buzzer,OUTPUT);
  pinMode(night_light,OUTPUT);
  pinMode(intruder_light,OUTPUT);
  pinMode(pir,INPUT);
  pinMode(photo,INPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  if(irrecv.decode(&results)){
   value = (results.value);
    irrecv.resume();
    Serial.println(value);
  }                       
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  if (value == 2295){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("Hello");
    lcd.setCursor(3,1);
    lcd.print("Dr. Bibek");
    analogWrite(buzzer,50);
    value = 0;
    delay(2000);
    analogWrite(buzzer,LOW);
    lcd.clear();
  }
    if (value == 34935){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("Hello");
    lcd.setCursor(3,1);
    lcd.print("Dr. Jenny");   
    analogWrite(buzzer,150);
    value = 0;
    delay(2000);
    analogWrite(buzzer,LOW);
    lcd.clear();
  }
    if (value == 18615){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("Hello");
    lcd.setCursor(3,1);
    lcd.print("Prof. X");
    analogWrite(buzzer,250);
    value = 0;
    delay(2000);
    analogWrite(buzzer,LOW);
    lcd.clear();
  }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  int x = digitalRead(pir);
  if (x==1){
    lcd.setCursor(4,0);
    lcd.print("Intruder");
    lcd.setCursor(5,1);
    lcd.print("Alert");
    digitalWrite(intruder_light,HIGH);
    delay(5000);
    digitalWrite(intruder_light,LOW);
    lcd.clear();
  }
 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   
	int y = digitalRead(button);
  if (y==1){
    lcd.setCursor(5,0);
    digitalWrite(intruder_light,LOW);
    lcd.print("GUEST");
    analogWrite(buzzer,20);
    delay(2000);
    lcd.clear();
    analogWrite(buzzer,LOW);
  }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
 if (analogRead(photo) > 150){
    digitalWrite(night_light,LOW);
  }
  else{
    digitalWrite(night_light,HIGH);
  }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}