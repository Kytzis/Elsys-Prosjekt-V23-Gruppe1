#include "screenController.h"

#define SCREEN_WIDTH 128    // OLED display width
#define SCREEN_HEIGHT 64    // OLED display height
#define OLED_RESET -1       // Default reset pin

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int test;

void setup() {
    init(&display);
    test = 1;
}

void loop() {
    write(String(test), &display);
    delay(100);
    ++test;
}
