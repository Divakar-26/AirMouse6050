#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22);  // ESP32 I2C pins (SDA = 21, SCL = 22)

    if (!mpu.begin()) {
        Serial.println("MPU6050 not found! Check wiring.");
        while (1);
    }

    // Set gyro range to ±1000°/s
    mpu.setGyroRange(MPU6050_RANGE_1000_DEG);
}

void loop() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // Get gyro data (°/s)
    float gyroX = g.gyro.x;
    float gyroY = g.gyro.y;

    // Send gyro values to PC via Serial
    Serial.print(gyroX);
    Serial.print(",");
    Serial.println(gyroY);

    delay(10);  // Small delay for smooth data flow
}
