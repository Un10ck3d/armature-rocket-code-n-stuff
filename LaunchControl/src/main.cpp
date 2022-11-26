#include "config.h"
#include "gyro.h"
#include "ota.h"
#include "socket.h"
#include "wifi.h"
#include <ArduinoOTA.h>
#include <ESPmDNS.h>
#include <WiFi.h>
#include <WiFiUdp.h>

void core0loop(void *pvParameters) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    // getDevices();
    /*digitalWrite(LED_BUILTIN, HIGH);
    delay(75);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(75);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);*/
    // client.write("IM STILL ALIVE!!");
    Serial.print("Acceleration X: ");
    Serial.print(a.acceleration.x);
    Serial.print(", Y: ");
    Serial.print(a.acceleration.y);
    Serial.print(", Z: ");
    Serial.print(a.acceleration.z);
    Serial.println(" m/s^2");

    Serial.print("Rotation X: ");
    Serial.print(g.gyro.x);
    Serial.print(", Y: ");
    Serial.print(g.gyro.y);
    Serial.print(", Z: ");
    Serial.print(g.gyro.z);
    Serial.println(" rad/s");

    Serial.print("Temperature: ");
    Serial.print(temp.temperature);
    Serial.println(" degC");
    // delay(50);
  }
}

void core1loop(void *pvParameters) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    ArduinoOTA.handle();
    mpu.getEvent(&a, &g, &temp);
    // delay(40);
  }
}

void setup() {
  Serial.begin(baud_rate);
  startWifi(ssid, password);
  startOTA(ota_port, ota_hostname, ota_password);
  // socket_connect(socket_port, socket_host);
  startMPU();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(LED_BUILTIN, OUTPUT);

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
