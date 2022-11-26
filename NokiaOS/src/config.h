#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>

// Multicore stuff
TaskHandle_t core0loophandle;
TaskHandle_t core1loophandle;

static uint8_t CoreZero = 0;
static uint8_t CoreOne = 1;

// Logging settings
const int baud_rate = 115200;

// Wifi settings
const char *ssid = "Titiwu";
const char *password = "TimTintenklecksUndDasHausschweinWutz";

// OTA settings

const int ota_port = 3232;
const char *ota_hostname = "esp_test";
const char *ota_password = "password";

// Socket settings

const uint16_t socket_port = 4000;
const char *socket_host = "home.bangert.dk";
WiFiClient client;

// MPU

Adafruit_MPU6050 mpu;
sensors_event_t a, g, temp;
// sensors_event_t test;

// Other settings
