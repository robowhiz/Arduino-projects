#include <SPI.h>

const int BUFFER_SIZE = 32;
char buffer[BUFFER_SIZE];
volatile byte pos = 0;

void setup() {
  Serial.begin(9600);
  
  // Initialize SPI as slave
  SPCR |= bit(SPE);
  
  // Enable SPI interrupt
  SPI.attachInterrupt();
}

void loop() {
  // Check if a complete message is received
  if (pos > 0) {
    // Null-terminate the buffer
    buffer[pos] = '\0';
    
    // Print the received message
    Serial.print("Received: ");
    Serial.println(buffer);
    
    // Reset the buffer position
    pos = 0;
  }
}

// SPI interrupt routine
ISR(SPI_STC_vect) {
  // Read the received byte
  byte receivedByte = SPDR;
  
  // Store the byte in the buffer
  if (pos < BUFFER_SIZE - 1) {
    buffer[pos++] = receivedByte;
  }
}