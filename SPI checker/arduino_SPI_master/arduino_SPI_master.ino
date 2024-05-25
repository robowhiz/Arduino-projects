#include <SPI.h>

#define SLAVE_SELECT_PIN 10 // Define the Slave Select pin

void setup() {
  // Initialize SPI as Master
  SPI.begin();
  Serial.begin(9600);
  // Set Slave Select pin as an output
  pinMode(SLAVE_SELECT_PIN, OUTPUT);
}

void loop() {
  // Select the slave
  digitalWrite(SLAVE_SELECT_PIN, LOW);
  
  // Send data to the slave
  int data = SPI.transfer(0x55); // Example data to send
  Serial.println(data);
  // Deselect the slave
  digitalWrite(SLAVE_SELECT_PIN, HIGH);
  
  // Wait before sending next data
  delay(1000);
}
