#include <WiFi.h>
#include <HTTPClient.h>


void initWiFi(const char* ssid, const char* password);

int getFrameIndex(String server);

String getFrame(String server, int frameIndex);
