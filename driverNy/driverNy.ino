#include "screenController.h"
ScreenController screen;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    screen = ScreenController();
}

void loop() {
    int test = 1;
    delay(100);
    // put your main code here, to run repeatedly:
    screen.write(F(test));
    ++test;
}
