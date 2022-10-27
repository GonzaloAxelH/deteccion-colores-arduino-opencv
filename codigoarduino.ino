#include <Servo.h>

Servo BASE;
Servo CODO1;
Servo CODO2;
Servo GIRATORIO;
Servo ANCLA; // aun no disponible
Servo PINZA;

int positionMotor6 = 50;
int positionMotor5 = 80;
int positionMotor4 = 30;
int positionMotor3 = 50;
int positionMotor2 = 100;
int positionMotor1 = 50;

int positionFinalMotor6 = 100;
int positionFinalMotor5 = 150;
int positionFinalMotor4 = 160;
int positionFinalMotor3 = 100;
int positionFinalMotor2 = 130;
int positionFinalMotor1 = 100;
String data = "";
String test = "";
int ABRE = 100;
int CIERRA = 50;
void setup()
{
    Serial.begin(9600);

    BASE.attach(2);
    CODO1.attach(3);
    CODO2.attach(4);
    GIRATORIO.attach(5);
    ANCLA.attach(6);
    PINZA.attach(7);

    BASE.write(150);
    CODO1.write(140);
    CODO2.write(153);
    GIRATORIO.write(105);
    ANCLA.write(50);
    PINZA.write(ABRE);
}

String RED = "00001\n";
String GREEN = "00002\n";
String BLUE = "00003\n";
// String RED ="red";
// String GREEN = "green";
// String BLUE = "blue";

boolean entradaCompleta = false;
void loop()
{
    Serial.println(data);
    if (entradaCompleta)
    {

        if (data == RED)
        {
            data = "";

            CODO1.write(120);
            delay(600);
            PINZA.write(CIERRA);
            delay(600);
            CODO2.write(100);
            delay(600);
            CODO1.write(150);
            delay(600);
            GIRATORIO.write(180);
            delay(600);
            BASE.write(100);
            delay(600);
            CODO2.write(153);
            delay(600);
            GIRATORIO.write(105);
            delay(600);
            CODO1.write(140);
            delay(600);

            PINZA.write(ABRE);
            // volver a la pocision original xd
            delay(2000);

            volver();
        }
        if (data == BLUE)
        {
            data = "";
            CODO1.write(120);
            delay(600);
            PINZA.write(CIERRA);
            delay(600);
            CODO2.write(100);
            delay(600);
            CODO1.write(150);
            delay(600);
            GIRATORIO.write(180);
            delay(600);
            BASE.write(85);
            delay(600);
            CODO2.write(153);
            delay(600);
            GIRATORIO.write(105);
            delay(600);
            CODO1.write(140);
            delay(600);

            PINZA.write(ABRE);
            // volver a la pocision original xd
            delay(2000);

            volver();
        }
        if (data == GREEN)
        {
            data = "";
            CODO1.write(120);
            delay(600);
            PINZA.write(CIERRA);
            delay(600);
            CODO2.write(100);
            delay(600);
            CODO1.write(150);
            delay(600);
            GIRATORIO.write(180);
            delay(600);
            BASE.write(75);
            delay(600);
            CODO2.write(123);
            delay(600);
            GIRATORIO.write(105);
            delay(600);
            CODO1.write(120);
            delay(600);

            PINZA.write(ABRE);
            // volver a la pocision original xd
            delay(2000);
            volver();
        }
    }
}

void serialEvent()
{
    while (Serial.available())
    {
        // Obtener bytes de entrada:
        char inChar =
            (char)Serial.read();
        // Serial.println(inChar);
        //  Agregar al String deentrada:
        data += inChar;
        if (inChar == '\n')
        {
            entradaCompleta = true;
        }
    }
}

void volver()
{

    CODO1.write(180);
    delay(600);
    GIRATORIO.write(180);
    delay(600);
    BASE.write(150);
    delay(600);
    CODO1.write(150);
    delay(600);
    CODO2.write(153);
    delay(600);
    GIRATORIO.write(105);
    delay(600);
    CODO1.write(140);
    delay(600);
}