#include "screenController.h"


void init(Adafruit_SSD1306* display) {
    if (!display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 Allocation failed"));
        for(;;); // Get stuck
    }
    display->display();
}

void write(String text, Adafruit_SSD1306* display) {
    display->clearDisplay();             // Clears display buffer
    display->setTextSize(1);             
    display->setTextColor(WHITE);       
    display->setCursor(0,0);             // Start printing at top-left corner
    display->println(text); 
    display->display();                  //displays the text on screen
}
