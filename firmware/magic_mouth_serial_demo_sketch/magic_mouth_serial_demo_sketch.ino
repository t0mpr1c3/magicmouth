/*

 Magic Mouth Serial Demo Sketch
 
 Open a Serial Monitor with a 9600 baud connection (or use another 
 serial terminal program such as Hyperterminal and specify 
 9600 bits per second, 8 data bits, 1 stop bit, no parity, and
 no flow control).

 Input to the console is received by the Arduino and echoed back
 over the serial connection and sent to the Magic Mouth shield
 (device 0x4F) on the I2C network. 
 
 For more information on the Magic Mouth Arduino Shield:
 http://is.gd/magicmouth
 
 */
 
 
#include <Wire.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  Wire.begin();
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    //Serial.println(inputString); 
    Wire.beginTransmission( 0x4F ); // Speech shield address in 7 bit format
    uint8_t i;
    for ( i = 0; i < inputString.length(); i++ )
    {
      Wire.write( inputString.charAt(i) );
      Serial.write( inputString.charAt(i) );
    }
    Wire.write( 0x0A );
    Wire.endTransmission();
    Serial.println();
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}



