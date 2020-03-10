import serial
import time

COM_PORT = 'COM3'
BAUD_RATE = 9600

ser = serial.Serial(COM_PORT, BAUD_RATE)

def main():
    # time.sleep(2)
    # b = ser.readline()
    # print("b = ", b)
    # type(b)
    # str_rn = b.decode()
    # print(str_rn)
    # type("str_rn = ", str_rn)
    print("Hello Aaron!")

if __name__ == "__main__":
    main()