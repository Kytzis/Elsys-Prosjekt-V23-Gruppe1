/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <vector>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#pragma once

#define SV0LO6_BMPWIDTH  128

void text(std::vector<String> tekst){
  for (int cnt = 0; cnt <sizeof(tekst); cnt++) {
    delay(2000);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 8);
    display.println(tekst[cnt]);
    display.display();
  }
}

std::vector<String> lyrics = {"Somebody once told me", "the world is gonna roll me", "I ain't the sharpest", "tool in the shed", "She was looking kind", "of dumb with her", "finger and her thumb", "In the shape of an", "'L' on her forehead"};

void setup() {

  Serial.begin(9600);
  //String lyrics = "Somebody once told me,the world is gonna roll me,I ain't the sharpest,tool in the shed,She was looking kind,of dumb with her,finger and her thumb,In the shape of an,'L' on her forehead";

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000); // Pause for 2 seconds
 
  // Clear the buffer.
  //display.clearDisplay();
  
  // Draw bitmap on the screen
  //display.drawBitmap(0, 0, bitmap_epic, 128, 64, 1);
  //display.display();
  
  // Display static text
  text(lyrics);
  }
  
void loop() {
  
}
