char command;

void setup() {
  Serial.begin(9600);  // Start serial communication
  Serial.println("Bluetooth ready. Waiting for command...");
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    Serial.print("Received: ");
    Serial.println(command);
  }
}
