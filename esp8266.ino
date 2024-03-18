#define MOTION_SENSOR_PIN D2
#define LED_PIN D3

bool motionDetected = false;

void setup() {
  pinMode(MOTION_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  motionDetected = digitalRead(MOTION_SENSOR_PIN);
  
  if (motionDetected) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion Detected - LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("No Motion Detected - LED OFF");
  }
  
  delay(500); // Adjust delay as needed
}
