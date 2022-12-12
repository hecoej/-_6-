#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Servo.h>
#define DHTPIN 7     // 디지털 7번핀 사용
#define DHTTYPE DHT11   // DHT 11 모델사용 (DHT21/22 사용 가능)

 
LiquidCrystal_I2C lcd(0x27,16,2); //LCD 설정 (I2C주소는 LCD의 종류에 따라 다르기때문에 LCD가 0x3F, 0x20, 0x27인지 확인하세요)
DHT dht(DHTPIN, DHTTYPE);
Servo servo_3;
 
void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);


  lcd.init();
  Serial.begin(9600);
  dht.begin();
  pinMode(A0, INPUT);
  Serial.begin(9600);

  servo_3.attach(3);
}
 
void loop() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

  float h = dht.readHumidity(); // 습도 측정
  float t = dht.readTemperature(); // 섭씨 온도 측정
  Serial.println(analogRead(A0));
   
  lcd.backlight();
  lcd.display();
  lcd.print("Temper: ");
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(h);
 
  Serial.print("H: ");
  Serial.print(h);
  Serial.print(" T: ");
  Serial.print(t);
  Serial.println();
  delay(1500); // Refresh
  lcd.clear();

  if(analogRead(A0)<900){
    servo_3.write(90);
  }
  else{
    servo_3.write(0);
  }
}