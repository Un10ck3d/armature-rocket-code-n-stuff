#include "config.h"
#include "gyro.h"
#include "ota.h"
#include "socket.h"
#include "wifi.h"
#include "sd.h"
#include "led_manager.h"
#include <ArduinoOTA.h>
#include <ESPmDNS.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <FS.h>
#include <SD_MMC.h>

void core0loop(void *pvParameters) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    // getDevices();
    // client.write("IM STILL ALIVE!!");
    //Serial.print("Acceleration X: ");
    //Serial.print(a.acceleration.x);
    //Serial.print(", Y: ");
    //Serial.print(a.acceleration.y);
    //Serial.print(", Z: ");
    //Serial.print(a.acceleration.z);
    //Serial.println(" m/s^2");

    //Serial.print("Rotation X: ");
    //Serial.print(g.gyro.x);
    //Serial.print(", Y: ");
    //Serial.print(g.gyro.y);
    //Serial.print(", Z: ");
    //Serial.print(g.gyro.z);
    //Serial.println(" rad/s");

    //Serial.print("Temperature: ");
    //Serial.print(temp.temperature);
    //Serial.println(" degC");
    delay(50);
    Serial.println("Huh ");
  }
}

void core1loop(void *pvParameters) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    if (DEBUG_MODE) {
      ArduinoOTA.handle();
      BlinkDebug(LED_BUILTIN);
    } else {
      BlinkNormal(LED_BUILTIN);
    }
    //mpu.getEvent(&a, &g, &temp);
    delay(40);
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_FLASH, OUTPUT);
  pinMode(PIN_DEBUG, INPUT_PULLUP);

  delay(500);

  digitalWrite(LED_BUILTIN, HIGH);

  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
  initMicroSDCard();
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(baud_rate);
  if (digitalRead(PIN_DEBUG) == LOW) {
    DEBUG_MODE = true;
    startWifi(ssid, password);
    startOTA(ota_port, ota_hostname, ota_password);
    digitalWrite(LED_BUILTIN, LOW);
    fs::FS &fs = SD_MMC;
    File file = fs.open(filename, FILE_APPEND);
    //file.println(WiFi.localIP().toString());
    file.println("heyo");
    file.close();
    BlinkWifi(LED_BUILTIN);
  }
  // socket_connect(socket_port, socket_host);
  //startMPU();
  digitalWrite(LED_BUILTIN, LOW);


  xTaskCreatePinnedToCore(core0loop,        /* Function to implement the task */
                          "core0loop",      /* Name of the task */
                          10000,            /* Stack size in words */
                          NULL,             /* Task input parameter */
                          2,                /* Priority of the task */
                          &core0loophandle, /* Task handle. */
                          CoreZero);        /* Core where the task should run */

  delay(250);

  xTaskCreatePinnedToCore(core1loop,        /* Function to implement the task */
                          "core0loop",      /* Name of the task */
                          10000,            /* Stack size in words */
                          NULL,             /* Task input parameter */
                          2,                /* Priority of the task */
                          &core1loophandle, /* Task handle. */
                          CoreOne);         /* Core where the task should run */
}

void loop() {}
