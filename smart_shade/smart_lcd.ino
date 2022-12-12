//서보모터 라이브러리 불러옴
#include <Servo.h>

Servo servo_3; //서보모터 이름정해줌

void setup()
{
  pinMode(A0, INPUT); //조도센서 
  Serial.begin(9600); //시리얼
  
  servo_3.attach(3); //3번 핀에 모터 등록
}

void loop()
{
  //조도센서 값을 보기위한 시리얼 출력
  Serial.println(analogRead(A0));
  
  //만약 900미만일때(어두울때) 서보모터 180도 적용
  //900이상일때(밝을때) 서보모터 0도 적용
  if(analogRead(A0) >= 12)
  {
    servo_3.write(0);
  }
  else {
    servo_3.write(90);
  }
  delay(2000);
}