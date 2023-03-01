#pragma once

struct screen {
    int width;
    int height;
    String data;
    screen(const int& w, const int& h, const String& d): width{w}, height{h}, data{d} {};
};
