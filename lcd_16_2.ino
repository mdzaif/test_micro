#include <LiquidCrystal.h>

String messageLine1 = "Hacking someone......"; // First row message
String messageLine2 = "Completed!";            // Second row message
int indexLine1 = 0;
int indexLine2 = 0;
LiquidCrystal lcd_1(13, 12, 11, 10, 9, 8);

void setup()
{
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  lcd_1.clear();      // Clear any previous display
}

void loop()
{
  // Typing effect for the first line (row 0)
  if (indexLine1 < messageLine1.length()) {
    lcd_1.setCursor(indexLine1, 0);         // Set cursor at the current character position on the first row
    lcd_1.print(messageLine1[indexLine1]);  // Print one character at a time
    indexLine1++;
    delay(10);                             // Delay for typing effect
  }
  // After fully printing the first line, start typing the second line
  else if (indexLine2 < messageLine2.length()) {
    lcd_1.setCursor(indexLine2, 1);         // Set cursor at the current character position on the second row
    lcd_1.print(messageLine2[indexLine2]);  // Print one character at a time
    indexLine2++;
    delay(10);                             // Delay for typing effect
  }

  // Stop further execution when both lines are printed
  if (indexLine1 >= messageLine1.length() && indexLine2 >= messageLine2.length()) {
  	delay(250);  // Optional delay to stop execution after printing
    indexLine1 = 0;
	indexLine2 = 0;
    lcd_1.clear();
  }
}
