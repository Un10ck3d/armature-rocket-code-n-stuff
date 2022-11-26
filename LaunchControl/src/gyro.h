#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

void startMPU() {
  while (!mpu.begin()) {
    Serial.println("Sensor init failed");
    delay(500);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
}
