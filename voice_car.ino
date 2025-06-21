// Motor Driver Pins
int motor1Pin1 = 2;   // IN1
int motor1Pin2 = 3;   // IN2
int motor2Pin1 = 4;   // IN3
int motor2Pin2 = 5;   // IN4

char command;  // Variable to receive Bluetooth command

void setup() {
  // Set all motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Start serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    command = tolower(command); // make command lowercase to avoid case issues

    switch(command) {
      case 'f': // forward
        forward();
        break;
      case 'b': // backward
        backward();
        break;
      case 'l': // left
        left();
        break;
      case 'r': // right
        right();
        break;
      case 's': // stop
        stopMotors();
        break;
      default:
        stopMotors();
    }
  }
}

void forward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void backward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void left() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void right() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
