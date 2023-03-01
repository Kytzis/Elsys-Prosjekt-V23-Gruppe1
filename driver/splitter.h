#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include <FS.h>
#include "screen.h"
#include <sstream>
#include <vector>
#include <Wire.h>


class splitter {
    std::stringsteam charbuffer;
    std::vector<screen> screens;
    void splitBuffer();
public:
    splitter();
    void addInput(std::stringstream& stream);
    screen& getScreen();
};
