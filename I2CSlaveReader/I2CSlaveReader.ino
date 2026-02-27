//REDIRECT_STDOUT_TO(Serial)

#include <Wire.h>

void receiveEvent(int howMany);

void setup()
{
  Serial.begin(115200);           // start serial for output
  while(!Serial);
#ifdef ARDUINO_ARCH_ZEPHYR
  printk("i2c slave reader start\n");
#endif
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  Serial.println("REQ");
#ifdef ARDUINO_ARCH_ZEPHYR
  printk("REQ\n");
#endif
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
#ifdef ARDUINO_ARCH_ZEPHYR
    printk("%c",c);
#endif
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
#ifdef ARDUINO_ARCH_ZEPHYR
  printk("%d\n",x);
#endif
}
