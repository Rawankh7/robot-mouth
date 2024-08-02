#include <LedControl.h>

// Pin definitions
int DIN = 12;  // Data In
int CS = 11;   // Chip Select
int CLK = 10;  // Clock

// Create an instance of the LedControl class
LedControl lc = LedControl(DIN, CLK, CS, 1); // The last parameter is the number of devices

void setup() {
  lc.shutdown(0, false);       // Wake up the display
  lc.setIntensity(0, 15);       // Set brightness level (0-15)
  lc.clearDisplay(0);          // Clear the display
}

void loop() {
  // Define the smiley mouth pattern with correct orientation
  byte SMILEY_MOUTH[8] = {
    0x00, // Row 0: Empty
    0x00, // Row 1: Empty
    0x00, // Row 2: Empty
    0x00, // Row 3: Empty
    0xff, // Row 4: 11111111 (smile part)
    0x42, // Row 5: 01000010
    0x3c, // Row 6: 00111100
    0x00  // Row 7: Empty
  };
  
  printByte(SMILEY_MOUTH);
  delay(1000);  // Display for 1 second
  
  // Optionally, you can clear the display or show another pattern
  lc.clearDisplay(0);  // Clear display after showing the smiley mouth
  delay(1000);  // Delay before repeating
}

// Function to print a pattern to the LED matrix
void printByte(byte character[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, character[i]);  // Set each row of the display with the pattern
  }
}
