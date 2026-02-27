#include <Wire.h>

void setup() {
  Wire.begin();        // join I2C bus (address optional for master)
  Serial.begin(115200);  // start serial for output
}

void loop() {
  Wire.requestFrom(16, 6);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read();
    Serial.write(c);         // print the character
  }
  Serial.println();
  delay(500);
}