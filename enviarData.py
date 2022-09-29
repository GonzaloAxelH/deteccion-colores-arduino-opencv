import serial
puerto = "COM3"
serialArduino = serial.Serial(puerto, 9600)
cadena = "g"



serialArduino.write(b"green\n")

