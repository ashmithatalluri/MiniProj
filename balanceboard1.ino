#include <VirtualWire.h>

/*
This sketch transmits a message if button is pressed
using the VirtualWire library
*/


const int transmitterPin = 12; 

// set the pins for controller buttons
const int buttonForward = 8;
const int buttonBack = 7;
const int buttonLeft = 6;
const int buttonRight = 5;

int buttonState = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Device is ready");
  vw_set_tx_pin(transmitterPin);
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
 

  
}

void loop() {  
  if (digitalRead(buttonForward) == HIGH) { // if forward button pressed
    send("f"); // send 'f' to sphere 
  
    Serial.println("we pressed f");
    delay(500);
  } else if (digitalRead(buttonRight) == HIGH) {
    send("r");
    delay(500);
  } else if (digitalRead(buttonLeft) == HIGH) {
    send("l");
    delay(500);
  } else if (digitalRead(buttonBack) == HIGH) {
    send("b"); 
    delay(500);
  }
}

void send (char *message) {
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}
