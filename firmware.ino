#include <Wire.h>
#include <Servo.h>
#include <Arduino.h>

// Variáveis para HC-SR04 -> sensor ultrassônico
const int TriggerPin = 5;
const int EchoPin    = 6; 
float pulse;
float d; 

// Variáveis para MPU6050 -> giroscópio e acelerômetro
float AccX, AccY, AccZ;
float AngleRoll;
float PrevAngRoll;
float LoopTimer;

// Variáveis para SG90 -> servo motor pequeno
Servo myservo;
int valX;

// Variável vibrador
int pinvibra = 2;

void gyro_signals(void) {
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1C);
  Wire.write(0x10);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(); 
  Wire.requestFrom(0x68,6);

  int16_t AccXLSB = Wire.read() << 8 | Wire.read();
  int16_t AccYLSB = Wire.read() << 8 | Wire.read();
  int16_t AccZLSB = Wire.read() << 8 | Wire.read();
  
  Wire.beginTransmission(0x68);
  Wire.write(0x1B); 
  Wire.write(0x8);
  Wire.endTransmission();                                                   
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);

  AccX=(float)AccXLSB/4096 -0.03;
  AccY=(float)AccYLSB/4096;
  AccZ=(float)AccZLSB/4096 +0.03;

  AngleRoll=atan(AccY/sqrt(AccX*AccX+AccZ*AccZ))*1/(3.142/180);
  myservo.attach(9);
}

void trigPulse(){
    digitalWrite(TriggerPin, LOW); 
    digitalWrite(TriggerPin,HIGH);
    delayMicroseconds(2);
    delayMicroseconds(10);
    digitalWrite(TriggerPin,LOW);
}

void setup() {
  Serial.begin(9600);

  myservo.write(0);
  pinMode(13, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(pinvibra, OUTPUT);

  digitalWrite(13, HIGH);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68); 
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
}


void loop() {
  gyro_signals();
  Serial.print("AngleRoll X= ");
  Serial.println(AngleRoll);

  valX = map(AngleRoll, -90, 90, 0, 180);

  if (fabs(AngleRoll - PrevAngRoll)>1){
    myservo.write(trunc(valX));
    Serial.print("\t TruncAngle= ");
    Serial.println(trunc(valX));
    delay(15);
  }
  PrevAngRoll = AngleRoll;

  digitalWrite(pinvibra, LOW);
  delayMicroseconds(2);
  digitalWrite(pinvibra,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinvibra, LOW);
  trigPulse();
  pulse = pulseIn(EchoPin, HIGH, 200000); 
  d = pulse/58.82;

  if (d < 50){ // cond pra saber se esta na area de atuação desejada
      digitalWrite(pinvibra, HIGH);
      Serial.println("Distância: ");
      Serial.println(d);
      Serial.print("cm.");
  }

  delay(50);
}
