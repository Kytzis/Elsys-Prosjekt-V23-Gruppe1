#include "screencontroller.h"

ScreenController::ScreenController() {
    _display = Adafruit_SSD1306(_width, _height, &Wire, _reset_pin);
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!_display.begin(SSD1306_SWITCHCAPVCC, _address)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
    Serial.println(F("Test"));
    delay(2000);
}

int ScreenController::write(String text) {
    _display.clearDisplay();             // Clears display buffer
    _display.setTextSize(1);             
    _display.setTextColor(WHITE);       
    _display.setCursor(0,0);             // Start printing at top-left corner
    _display.println(F("Test")); 
    _display.display();                  //displays the text on screen
}
