#pragma once

#include <HTTPClient.h>
#include <sstream>
#include <WiFi.h>

class wifiController {
    const char* ssid;
    const char* password;   
    const String server;
    int prevTextNumber = -1;

public:
    std::stringstream data;
    wifiController(const char* ssid, const char* password, const String server);
    int tryGetMoreData();
};
