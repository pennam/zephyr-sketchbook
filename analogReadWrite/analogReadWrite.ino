#define READ_PIN_0  A0
#define READ_PIN_1  A1
#define PWM_PIN     D5   

void setup() {        
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("\n=== Analog Input/Output test ===");
  Serial.println("Setup:");
  Serial.println(" - Connect A0 to GND, A1 to 3.3V");
  Serial.println(" - Connect scope/logic analyzer to PWM_PIN for PWM waveform");
}

void loop() {
  int a0 = analogRead(READ_PIN_0);
  int a1 = analogRead(READ_PIN_1);
  Serial.print("Analog read A0=");
  Serial.print(a0);
  Serial.print(" A1=");
  Serial.println(a1);
  analogWrite(PWM_PIN, 128);  // 50% duty cycle PWM
  
  while (true) {
    // Loop forever, or until reset
  }
}