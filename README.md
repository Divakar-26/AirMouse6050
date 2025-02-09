# AIrMouse Prototype 
This AirMouse prototype is a simple project made using an ESP32 and an MPU6050 gyro sensor, along with Python's pynput library


## Working
The first step of this project is to calculate the tilt angle using the MPU6050's accelerometer and gyroscope data. for more -> https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/?utm_source=chatgpt.com.
After calculation, with the use of python's pynput library we can move cursor. cursor move according to this formula (TILT_ANGLE * SENSITIVITY). the x-direction motion is inverted so that it feels like normal mouse. 

## Circuit Diagram
![ESP32-MPU6050](https://github.com/Divakar-26/AirMouse6050/blob/main/MPU6050%20Interfacing%20with%20ESP32.jpg)

## Result
![Working](https://github.com/Divakar-26/AirMouse6050/blob/main/Untitled%20video%20-%20Made%20with%20Clipchamp%20(2).gif)
