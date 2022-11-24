// Multicore stuff
TaskHandle_t core1loophandle;
TaskHandle_t core2loophandle;

// Logging settings
const int baud_rate = 115200;

// Wifi settings
const char* ssid = "Titiwu";
const char* password = "TimTintenklecksUndDasHausschweinWutz";

// OTA settings

const int ota_port = 3232;
const char* ota_hostname = "esp_test";
const char* ota_password = "password";

// Socket settings

const uint16_t socket_port = 7531;
const char * socket_host = "192.168.20.241";
WiFiClient client;

// Other settings
