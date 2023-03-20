#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128    // OLED display width
#define SCREEN_HEIGHT 64    // OLED display height
#define OLED_RESET     -1   // Reset pin number, -1 means Arduino reset pin
#define SCREEN_ADDRESS 0x3C // Address may be either 3C or 3d


class ScreenController {
private:
    Adafruit_SSD1306 _display;
    int _width = SCREEN_WIDTH;
    int _height = SCREEN_HEIGHT;
    int _reset_pin = OLED_RESET;
    byte _address = SCREEN_ADDRESS;

public:
    ScreenController();
    int write(String text);
};
