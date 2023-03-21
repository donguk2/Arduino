#define TRIG1 3  //  1번 초음파 센서 Trig 핀 번호
#define ECHO1 4  //  1번 초음파 센서 Echo 핀 번호

#define TRIG2 5  //  2번 초음파 센서 Trig 핀 번호
#define ECHO2 6  //  2번 초음파 센서 Echo 핀 번호

#define TRIG3 7  //  3번 초음파 센서 Trig 핀 번호
#define ECHO3 8  //  3번 초음파 센서 Echo 핀 번호

void setup() {
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
  
  Serial.begin(115200); // 통신 속도를 115200으로 정의
}

long sonar1(void) {
  long duration1, distance1;

  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);

  duration1 = pulseIn(ECHO1, HIGH);
  distance1 = ((float)(340 * duration1) / 1000) / 2;
  return distance1;
}
long sonar2(void) {
  long duration2, distance2;

  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);

  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = ((float)(340 * duration2) / 1000) / 2;
  return distance2;
}
long sonar3(void) {
  long duration3, distance3;

  digitalWrite(TRIG3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG3, LOW);

  duration3 = pulseIn(ECHO3, HIGH);
  distance3 = ((float)(340 * duration3) / 1000) / 2;
  return distance3;
}

void loop() {
  //Serial.print("Duration: ");
  //Serial.println(sonar1());
  Serial.print("Distance1: ");
  Serial.print(sonar1()       );
  Serial.print("Distance2: ");
  Serial.print(sonar2()       );
  Serial.print("Distance3: ");
  Serial.println(sonar3());
  //Serial.println("mm\n");
  delay(500);
}
