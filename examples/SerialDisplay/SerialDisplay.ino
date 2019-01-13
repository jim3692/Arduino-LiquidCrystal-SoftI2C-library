/**
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 */
#include <LiquidCrystal_SoftI2C.h>

// Set SDA to pin 10 and SCL to pin 11
SoftwareWire *wire = new SoftwareWire(10, 11);
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2, wire);

void setup()
{
	lcd.begin();
	lcd.backlight();
  
	// Initialize the serial port at a speed of 9600 baud
	Serial.begin(9600);
}

void loop()
{
	// If characters arrived over the serial port...
	if (Serial.available()) {
		// Wait a bit for the entire message to arrive
		delay(100);
		// Clear the screen
		lcd.clear();

		// Write all characters received with the serial port to the LCD.
		while (Serial.available() > 0) {
			lcd.write(Serial.read());
		}
	}
}
