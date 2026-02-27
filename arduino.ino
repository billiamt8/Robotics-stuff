// C++ code

#include <Servo.h>

Servo myservo;

const int audio = A2;

const int btn = 11;

const int buzz = 7;

const int In1 = 9;

const int In2 = 8;

const int EnA = 10;

const int pot = A1;

const int trig = 5;

const int echo = 4;

const int LED = 2;


void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(btn, INPUT);

  pinMode(LED, OUTPUT);

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

void loop() {
  int input = analogRead(pot);
  int val = analogRead(pot);
  val = map(val, 0, 1023, 0, 100);



  {
    ButtonBuzzer();
    goStraight();
    UltrasonicLED();

  }
}

long distanceConvert(long microSeconds) {
  return microSeconds / 29 / 2;
}




void goStraight()  //run both motors in the same direction

{

  // turn on motor A

  analogWrite(EnA, 105);

  digitalWrite(In1, HIGH);

  digitalWrite(In2, LOW);

  // now turn off motors
  delay(500);

  digitalWrite(In1, LOW);

  digitalWrite(In2, LOW);

  analogWrite(EnA, 60);

  digitalWrite(In1, LOW);

  digitalWrite(In2, HIGH);
}


void UltrasonicLED()
{
  int distance;
  long duration, cm;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  cm = distanceConvert(duration);

  Serial.println(duration); 

  distance = duration * 0.0344 / 3;

  int ledBrightness = map(distance, 0, 200, 255, 0);

  ledBrightness = constrain(ledBrightness, 0, 255);

  analogWrite(LED, ledBrightness);

}

void ButtonBuzzer()
{
    bool pressed = digitalRead(btn);
    if (pressed) {
      tone(buzz, 500);
    } else
      noTone(buzz);
}
