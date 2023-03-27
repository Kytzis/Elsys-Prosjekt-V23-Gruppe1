#include "screenController.h"
#include "wifiController.h"

#define SCREEN_WIDTH 128    // OLED display width
#define SCREEN_HEIGHT 64    // OLED display height
#define OLED_RESET -1       // Default reset pin

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "HUAWEI Mate 20 lite";
const char* password = "Stian=DummeUnge";
String serverIP = "http://192.168.116.202:8000/";
int curFrameIndex = -1;
int frameIndex;
String payload;


void setup() {
    Serial.begin(57600);
    Serial.println("Initializing display");
    init(&display);
    Serial.println("Initializing WiFi");
    initWiFi(ssid, password);
}

void loop() {
    frameIndex = getFrameIndex(serverIP);
    if (frameIndex == -1) {
        initWiFi(ssid, password);
    }
    if (frameIndex >= 0 && frameIndex != curFrameIndex) {
        curFrameIndex = frameIndex;
        payload = getFrame(serverIP, frameIndex);
        write(String(payload), &display);
    }
}
