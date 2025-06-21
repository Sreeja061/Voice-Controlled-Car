const int in1 = 2, in2 = 3, in3 = 4, in4 = 5;
void setup() {
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Motor test ready. Send F, B, L, R, or S.");
}
void loop() {
  if (Serial.available()) {
    char c = toupper(Serial.read());
    switch(c) {
      case 'F': forward();    break;
      case 'B': backward();   break;
      case 'L': turnLeft();   break;
      case 'R': turnRight();  break;
      case 'S': stopAll();    break;
    }
    Serial.print("Cmd: "); Serial.println(c);
  }
}
void forward()   { digitalWrite(in1,HIGH); digitalWrite(in2,LOW);
                  digitalWrite(in3,HIGH); digitalWrite(in4,LOW); }
void backward()  { digitalWrite(in1,LOW); digitalWrite(in2,HIGH);
                  digitalWrite(in3,LOW); digitalWrite(in4,HIGH); }
void turnLeft()  { digitalWrite(in1,LOW); digitalWrite(in2,HIGH);
                  digitalWrite(in3,HIGH); digitalWrite(in4,LOW); }
void turnRight() { digitalWrite(in1,HIGH); digitalWrite(in2,LOW);
                  digitalWrite(in3,LOW); digitalWrite(in4,HIGH); }
void stopAll()   { digitalWrite(in1,LOW); digitalWrite(in2,LOW);
                  digitalWrite(in3,LOW); digitalWrite(in4,LOW); }
