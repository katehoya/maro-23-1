#include <Servo.h>

Servo myservo;  
Servo servo;    


int pos = 0;    // variable to store the servo position
int button0 = 9;
int relay_pin=10;
int relay_pin1=11;
int relay_pin2=6;
int value=0;


void setup() {
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  servo.attach(7);
  
  pinMode(button0,INPUT);
  pinMode(relay_pin,OUTPUT); 
  pinMode(relay_pin1,OUTPUT);
  pinMode(relay_pin2, OUTPUT); 
  servo.write(65);       


}

void loop() {
  if(digitalRead(button0)==HIGH){

    servo.write(0); // 얼음넣기
    delay(350);
    servo.write(65);


    digitalWrite(relay_pin, LOW); // 물넣기
    delay(3500);
    myservo.write(500); // 가루넣기
    delay(3000);
    
    digitalWrite(relay_pin, HIGH); // 물 멈춤
    delay(2000);

    
    myservo.write(90); // 가루멈춤
    delay(2000);

    
    digitalWrite(relay_pin2,LOW);//가루 섞기
    delay(8000);
    digitalWrite(relay_pin2,HIGH);//섞기 멈춤
    delay(500);

    
    digitalWrite(relay_pin1, LOW); //아이스티 옮기기
    delay(10000);
    digitalWrite(relay_pin1, HIGH);
    delay(500);
      
  }
  else{
    digitalWrite(relay_pin,HIGH);
    digitalWrite(relay_pin1,HIGH);
    digitalWrite(relay_pin2,HIGH);
    myservo.write(90);
    //analogWrite(outPin, 0);
    delay(100);
  }
}