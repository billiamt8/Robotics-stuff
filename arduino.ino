// C++ code

#include <Servo.h>

Servo myservo;

const int audio = A2;

const int btn = 12;

const int buzz = 11;

const int In1 = 9;

const int In2 = 8;

const int EnA = 10;

const int pot = A1;
  
const int trig = 5;

const int echo = 4;



void setup()
{
  pinMode(buzz, OUTPUT);
  pinMode(btn, INPUT);

	pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(In1, OUTPUT);

  pinMode(In2, OUTPUT);

  pinMode(EnA, OUTPUT);

  pinMode(pot, INPUT);
  pinMode(audio, INPUT);

  myservo.attach(6);
  Serial.begin(9600);
}

void loop()
{
 myservo.write(0);
  delay(500);
  myservo.write(20);
  delay(500);


  long duration, cm;
 
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  
  cm = distanceConvert(duration);
  
  Serial.println(duration);
}
long distanceConvert(long microSeconds) {
  return microSeconds / 29 / 2;



  int input = analogRead(pot);
  Serial.println(input);
{
  bool pressed = digitalRead(btn);
  if (pressed) {
    tone(buzz, 500);
      delay(300);
      tone(buzz, 300);
    delay(300);
    tone(buzz, 500);
   	delay(buzz);
  }
  else 
     noTone(buzz);
}
  
       int val = analogRead(pot);
  
  val = map(val, 0, 1023, 0, 100);
  
  Serial.println(val);
   
{

  goStraight();

  delay(1000);

}
}




void goStraight()   //run both motors in the same direction

{

  // turn on motor A

  analogWrite(EnA, 105);

  digitalWrite(In1, HIGH);

  digitalWrite(In2, LOW);


  delay(2000);

  // now turn off motors

  digitalWrite(In1, LOW);

  digitalWrite(In2, LOW);  

  delay(2000);

  analogWrite(EnA, 60);

  digitalWrite(In1, LOW);

  digitalWrite(In2, HIGH);
}



