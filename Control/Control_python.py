import serial
import time
import pyautogui

#set correct port and baudrate
ser = serial.Serial("COM3",115200,timeout=1)

while 1:
    
    dat = ser.readline()
    dat = dat.strip().decode()
    dat = dat.split(",")

    #dat shows the list of x and y element updated
    #do processing onward

    x = int(float(dat[0]))
    y = int(float(dat[1]))
    
    #Setting up the Keyboard controll over the gesture

    if -4>=y:
        pyautogui.keyDown('s')
        # print("y down")
        pyautogui.keyUp('s')
    if 4<=y:
        pyautogui.keyDown('w')
        # print('y up')
        pyautogui.keyUp('w')
    if x<=-5:
        pyautogui.keyDown('d')
        # print("x right")
        pyautogui.keyUp('d')
    if x>=5:
        pyautogui.keyDown('a')
        # print("x left")
        pyautogui.keyUp('a')
    else:
        None


ser.close()
