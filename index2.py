
import cv2
import numpy as np
import serial
import time
ser = serial.Serial('COM4',9600)
cambiar_color = 1 # azul 1, rojo 2, amarillo3
parte_brazo = 1 # giro brazo 1 , muñeca 2
pinta = 0
posY = 0
bucle = True


def dibujar(mask, color):
    contornos, _ = cv2.findContours(mask,
    cv2.RETR_EXTERNAL,
    cv2.CHAIN_APPROX_SIMPLE)
    for c in contornos:
        area=cv2.contourArea(c)
        if area > 6000:
            M = cv2.moments(c)
            if (M["m00"]==0):
                M["m00"]=1
            x = int(M["m10"]/M["m00"])
            y = int(M['m01']/M['m00'])
            cv2.circle(frame, (x,y), 7,(0,0,255), -1)
            cv2.putText(frame,'{},{}'.format(x,y),(x+10,y), font,1.2,(0,0,255),2,cv2.LINE_AA)    
            nuevoContorno=cv2.convexHull(c)
            cv2.drawContours(frame,[nuevoContorno], 0 ,color, 3)
            if x < 55:
                print("mover a la izquierda 0")
                ser.write(b"00001\n")
            elif x >= 55 and x < 110:
            #print("Mover a la izquierda 30")
                ser.write(b"00401\n")
            elif x >= 110 and x < 165:
            #print("Mover a la izquierda60")
                ser.write(b"00801\n")
            # Mover al centro
            elif x >= 165 and x < 220:
                print("Mover al centro 90")
                ser.write(b"01201\n")
            elif x >= 220 and x < 275:
                print("moviendo a la derecha120")
                ser.write(b"01601\n")
            elif x >= 275 and x < 330:
                print("moviendo a la derecha150")
                ser.write(b"02001\n")
            elif x >= 330 and x < 385:
                print("moviendo a la derecha150")
                ser.write(b"02401\n")
            elif x >= 385 and x < 440:
                print("moviendo a la derecha150")
                ser.write(b"02801\n")
            elif x >= 440 and x < 495:
                print("moviendo a la derecha150")
                ser.write(b"03201\n")
            elif x >= 495 and x < 550:
                print("moviendo a la derecha150")
                ser.write(b"03601\n")
            elif x >= 550:
                print("Moviendo a la derecha180")
                ser.write(b"04001\n")
            if y < 70:
                print("Mover a la izquierda 0")
                ser.write(b"00002\n")
            elif y >= 70 and y < 140:
                print("Mover a la izquierda30")
                ser.write(b"01002\n")
            elif y >= 140 and y < 210:
                print("Mover a la izquierda60")
                ser.write(b"02002\n")
                # Mover al centro
            elif y >= 210 and y < 280:
                print("Mover al centro 90")
                ser.write(b"03002\n")
            elif y >= 350 and y < 420:
                print("moviendo a la derecha120")
                ser.write(b"04002\n")
            elif y >= 420 and y < 490:
                print("moviendo a la derecha150")
                ser.write(b"05002\n")
            elif y >= 490:
                print("Moviendo a la derecha180")
                ser.write(b"06002\n")
                ##empuje
            if cv2.waitKey(1) == ord('l'):
                ser.write(b"03005\n")
            if cv2.waitKey(1) == ord('m'):
                ser.write(b"06005\n")
            ######pinza
            if cv2.waitKey(1) == ord('o'):
                ser.write(b"15003\n")
            if cv2.waitKey(1) == ord('p'):
                ser.write(b"06004\n")
            ####botar
            if cv2.waitKey(1) == ord('k'):
                ser.write(b"00007\n")
            ####retonar despues de botar
            if cv2.waitKey(1) == ord('j'):
                ser.write(b"00008\n")
            #else:
            # print("nohay nada")
            pinta = 1
def reiniciar():
    ser.write(b"00008\n")
    cap = cv2.VideoCapture(1)
    bucle = True

cap = cv2.VideoCapture(1)
azulBajo = np.array([100,100,20], np.uint8)
azulAlto = np.array([125,255,255], np.uint8)
amarilloBajo = np.array([15,100,20],np.uint8)
amarilloAlto =np.array([45,255,255],np.uint8)
rojoBajo1 = np.array([0,100,20], np.uint8)
rojoAlto1 = np.array([8,255,255], np.uint8)
#rojoBajo2 = np.array([170,100,20], np.uint8)
#rojoAlto2 = np.array([179,255,255],np.uint8)
font = cv2.FONT_HERSHEY_SIMPLEX

while bucle == True:
    if cambiar_color == 1 :
        ret, frame = cap.read()
        if ret:
            frame = cv2.flip(frame, 1)
            frameHSV=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
            maskAzul = cv2.inRange(frameHSV,azulBajo,azulAlto)
            dibujar(maskAzul,(255,0,0))
            #print(pinta)
            cv2.imshow('frame',frame)
            if cv2.waitKey(1) & 0xFF == ord('s'):
                cv2.destroyAllWindows()
                break
            if cv2.waitKey(1) == ord('r'):
                cambiar_color = 2
            if cv2.waitKey(1) == ord('y'):
                cambiar_color = 3
            if cv2.waitKey(1) == ord('x'):
                ser.write(b"00007\n")
                bucle = False
                time.sleep(2.4)
                reiniciar()
    elif cambiar_color == 2:
        ret, frame = cap.read()
        if ret:
            frame = cv2.flip(frame, 1)
            frameHSV=cv2.cvtColor(frame,
            cv2.COLOR_BGR2HSV)
            maskRed1=cv2.inRange(frameHSV,rojoBajo1,rojoAlto1)
            dibujar(maskRed1,(0,0,255))
            cv2.imshow('frame',frame)
            if cv2.waitKey(1) & 0xFF ==ord('s'):
               cv2.destroyAllWindows()
               break
            if cv2.waitKey(1) == ord('b'):
               cambiar_color = 1
            if cv2.waitKey(1) == ord('y'):
               cambiar_color = 3
            if cv2.waitKey(1) == ord('x'):
               ser.write(b"00007\n")
               bucle = False
               time.sleep(2.4)
               reiniciar()
    elif cambiar_color == 3:
        ret, frame = cap.read()
        if ret:
            frame = cv2.flip(frame, 1)
            frameHSV=cv2.cvtColor(frame,
            cv2.COLOR_BGR2HSV)
            maskAmarillo = cv2.inRange(frameHSV,amarilloBajo,amarilloAlto)
            dibujar(maskAmarillo,(0,255,255))
            cv2.imshow('frame',frame)
            if cv2.waitKey(1) & 0xFF == ord('s'):
                cv2.destroyAllWindows()
                break
            if cv2.waitKey(1) == ord('b'):
                cambiar_color = 1
            if cv2.waitKey(1) == ord('r'):
                cambiar_color = 2
            if cv2.waitKey(1) == ord('x'):
                ser.write(b"00007\n")
                bucle = False
                time.sleep(1.8)
                reiniciar()
           
    else:
        print("color invalido")
    