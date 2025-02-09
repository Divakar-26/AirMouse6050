import serial
from pynput.mouse import Controller
import time

cursor = Controller()

ser = serial.Serial('COM7', 115200, timeout=1)

SENSITIVITY = 0.2
SPEED = 2


def moveMouse(dx, dy):
    move_x = dx * SENSITIVITY * SPEED
    move_y = dy * SENSITIVITY * SPEED
    # x,y = mouse.position
    move_x = -move_x
    cursor.move(move_y, move_x)


while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode('utf-8').strip()
        
        try:
            dx,dy = map(float, data.split(","))
            dx = int(dx)
            dy = int(dy)
            print(dx,dy)
            moveMouse(dx,dy)
            # cursor(dx, dy, x, y)
        
        except ValueError:
            print("Invalid data received:", data)

    time.sleep(0.01)
