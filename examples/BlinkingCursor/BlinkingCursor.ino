#include <LiquidCrystal_SoftI2C.h>

// Set SDA to pin 10 and SCL to pin 11
SoftwareWire *wire = new SoftwareWire(10, 11);
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2, wire);

void setup()
{
	// initialize the LCD
	lcd.begin();
}

void loop()
{
	bool blinking = true;
	lcd.cursor();

	while (1) {
		if (blinking) {
			lcd.clear();
			lcd.print("No cursor blink");
			lcd.noBlink();
			blinking = false;
		} else {
			lcd.clear();
			lcd.print("Cursor blink");
			lcd.blink();
			blinking = true;
		}
		delay(4000);
	}
}
