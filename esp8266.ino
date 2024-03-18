#include <DmxSimple.h>

#define MOTION_SENSOR_PIN D2
#define DMX_CHANNEL 1 // The DMX channel to control the LED
#define MOTION_DETECTED_LEVEL HIGH // Level at which motion is detected

bool motionDetected = false;

void setup() {
  pinMode(MOTION_SENSOR_PIN, INPUT);
  DmxSimple.usePin(3); // Specify the pin used for DMX communication
  DmxSimple.maxChannel(1); // Set the maximum DMX channel
  Serial.begin(115200);
}

void loop() {
  motionDetected = digitalRead(MOTION_SENSOR_PIN);
  
  if (motionDetected) {
    DmxSimple.write(DMX_CHANNEL, 255); // Turn on the LED at full brightness
    Serial.println("Motion Detected - LED ON");
  } else {
    DmxSimple.write(DMX_CHANNEL, 0); // Turn off the LED
    Serial.println("No Motion Detected - LED OFF");
  }
  
  delay(500); // Adjust delay as needed
}
