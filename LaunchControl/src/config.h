#include <ESP8266WiFi.h>

// Logging settings
const int baud_rate = 115200;

// Wifi settings
const char *ssid = "Titiwu";
const char *password = "TimTintenklecksUndDasHausschweinWutz";

// OTA settings

const int ota_port = 3232;
const char *ota_hostname = "launch-control";
const char *ota_password = "password";

// Socket settings

const uint16_t socket_port = 4000;
const char *socket_host = "home.bangert.dk";
WiFiClient client;

// Other settings
