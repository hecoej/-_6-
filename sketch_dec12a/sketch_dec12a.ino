int echoPin = 2;
int trigPin = 3;
int traffic_red = 8;
int traffic_yellow = 9;
int traffic_green = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(traffic_red, OUTPUT);
  pinMode(traffic_yellow, OUTPUT);
  pinMode(traffic_green, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = ( (float) (340 * duration) / 10000 ) / 2;

  Serial.print(distance);
  Serial.println("cm");

  digitalWrite(traffic_red, LOW);
  digitalWrite(traffic_yellow, HIGH);
  digitalWrite(traffic_green, LOW);
  
  if(distance < 16){
    digitalWrite(traffic_red, HIGH); //GREEN
  }
  // else if(distance >= 20 && distance < 25){
  //   digitalWrite(traffic_yellow, HIGH); //X
  // }
  else if(distance > 16){
    digitalWrite(traffic_green, HIGH); //RED
  }
  delay(200);
}
