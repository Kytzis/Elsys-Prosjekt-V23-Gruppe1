#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FS.h>
#include <vector>
using namespace std;

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET     -1 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displayList(String* list, int numItems){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  for (int i = 0; i < numItems; i+=4){
    display.setCursor(0, 0);
    for (int j = 0; j < 4 && i+j < numItems; j++){
      display.println(list[i+j]);
    }
    display.display();
    delay(2000);
    display.clearDisplay();
  }
}

void setup() {
  Serial.begin(9600); // set up serial communication at 9600 bps
  Wire.begin(); // initialize the Wire library

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  //display.clearDisplay();
  //display.setTextSize(2);
  //display.setTextColor(WHITE);
  //display.println("Hei");
  //display.display();
}

void loop() {
  char inputString[] = "Onsdag morgen fortsetter demonstrasjonene mot at vindturbinene på Fosen i Trøndelag, som Høyesterett har sagt bryter samiske rettigheter, ikke er revet. De siste dagene har aksjonistene sperret inngangene til Finansdepartementet og Olje- og energidepartementet. Nå blokkeres også inngangen til Klima- og miljødepartementet og Næringsdepartementet.";
  char* token;
  char delimiters[] = " ";
  int i = 0;
  char* words[100];  // assuming a maximum of 100 words in the string
  
  token = strtok(inputString, delimiters);
  while (token != NULL) {
    words[i] = token;
    i++;
    token = strtok(NULL, delimiters);
  }

  int t = millis();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(t);
  display.display();

  String* printWords = new String[100];  // assuming a maximum of 100 words in the string
  int numWords = 0;
  String temp = "";
  for (int k = 0; k < i; k++){
    if((temp.length() + strlen(words[k]) + 1) <= 20){
      if(temp.length()>0){
        temp += " ";
      }
      temp += words[k];
    }
    else{
      printWords[numWords] = temp;
      numWords++;
      temp = String(words[k]);
    }
    // if(strlen(words[k]) >= 20){
    //   printWords[numWords] = String(words[k]);
    //   numWords++;
    // }
  }

  if(temp.length() > 0){
    printWords[numWords] = temp;
    numWords++;
  }
  
  //display.clearDisplay();
  //display.setTextSize(2);
  //display.setTextColor(WHITE);
  //display.println(t-millis());
  //display.display();
  
  for (int j = 0; j < numWords; j++) {
    Serial.println(printWords[j]);
  }

  displayList(printWords, numWords);

  delete[] printWords;

  delay(10000);
}
