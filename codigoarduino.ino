#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
String entradaSerial = ""; //
// String para almacenar entrada
String entradaSerialTemp = "";
// String para almacenar entrada
bool entradaCompleta = false; //
// Indicar si el String está completo
String servoActuar = "";
int angulo = 0; // Variable para
// guardar el angulo que deseamos de giro
char leer;
boolean activo = false;
void setup()
{
    servo6.attach(8); // codo
    servo1.attach(2); // giro
    servo2.attach(2); // muñeca
    servo3.attach(3); // pinza
    servo4.attach(4); // base brazo
    servo5.attach(5); // base brazo
    Serial.begin(9600);
    servo1.write(0);
    servo2.write(0);
    servo3.write(150); // PINZA abierta
    servo4.write(30);
    servo5.write(30);
    servo6.write(20);
}

void loop()
{

    if (servoActuar == "01\n")
    {
        if (entradaSerial == "00001\n")
        {
            servo1.write(0);
        }
        else if (entradaSerial ==
                 "00401\n")
        {
            servo1.write(4);
        }
        else if (entradaSerial ==
                 "00801\n")
        {
            servo1.write(8);
        }
        else if (entradaSerial ==
                 "01201\n")
        {
            servo1.write(12);
        }
        else if (entradaSerial ==
                 "01601\n")
        {
            servo1.write(16);
        }
        else if (entradaSerial ==
                 "02001\n")
        {
            servo1.write(20);
        }
        else if (entradaSerial ==
                 "02401\n")
        {
            servo1.write(24);
        }
        else if (entradaSerial ==
                 "02801\n")
        {
            servo1.write(28);
        }
        else if (entradaSerial ==
                 "03201\n")
        {
            servo1.write(32);
        }
        else if (entradaSerial ==
                 "03601\n")
        {
            servo1.write(36);
        }
        else if (entradaSerial ==
                 "04001\n")
        {
            servo1.write(40);
        }
        else
        {
            entradaSerial = "";
        }
        entradaSerial = "";
        // entradaCompleta = false;
    }
    if (servoActuar == "02\n")
    {
        if (entradaSerial == "00002\n")
        {
            servo2.write(0);
            // abrePinza();
            // pinza();
        }
        else if (entradaSerial ==
                 "01002\n")
        {
            servo2.write(10);
            // pinza();
        }
        else if (entradaSerial ==
                 "02002\n")
        {
            servo2.write(20);
            // abrePinza();
            // pinza();
        }
        else if (entradaSerial ==
                 "03002\n")
        {
            servo2.write(30);
            // pinza();
        }
        else if (entradaSerial ==
                 "04002\n")
        {
            servo2.write(40);
            // pinza();
        }
        else if (entradaSerial ==
                 "05002\n")
        {
            servo2.write(50);
            // pinza();
        }
        else if (entradaSerial ==
                 "06002\n")
        {
            servo2.write(60);
        }
        else
        {
            entradaSerial = "";
        }
        entradaSerial = "";
        // entradaCompleta = false;
    }
    // empujar
    if (servoActuar == "05\n")
    {
        if (entradaSerial == "03005\n")
        {
            servo4.write(30);
            servo5.write(30);
        }
        else if (entradaSerial ==
                 "06005\n")
        {
            servo4.write(60);
            servo5.write(60);
        }
        else
        {
            entradaSerial = "";
        }
        entradaSerial = "";
    }
    // pinza
    if (servoActuar == "03\n")
    {
        if (entradaSerial == "15003\n")
        {
            servo3.write(150);
        }
        else
        {
            entradaSerial = "";
        }
        entradaSerial = "";
    }
    if (servoActuar == "04\n")
    {
        if (entradaSerial == "06004\n")
        {
            servo3.write(60);
        }
        else
        {
            entradaSerial = "";
        }
        entradaSerial = "";
    }
    // botar
    if (servoActuar == "07\n")
    {
        if (entradaSerial == "00007\n")
        {
            servo1.write(120);
            // LowPower.idle(SLEEP_2S,
            // ADC_OFF, TIMER2_OFF, TIMER1_OFF,
            //      TIMER0_OFF, SPI_OFF, USART0_OFF,
            //        TWI_OFF);
            servo3.write(150);
        }
        else
        {
            entradaSerial = "";
        }
        entradaSerial = "";
    }
    // retornar
    if (servoActuar == "08\n")
    {
        if (entradaSerial == "00008\n")
        {
            servo1.write(0);
        }
        else
        {
            entradaSerial = "";
        }
        entradaSerial = "";
    }
}
// Función que se activa al recibiralgo por
// el puerto serie, Interrupción delPuerto Serie.
void serialEvent()
{
    while (Serial.available())
    {
        // Obtener bytes de entrada:
        char inChar =
            (char)Serial.read();
        // Serial.println(inChar);
        //  Agregar al String deentrada:
        entradaSerial += inChar;
    }
    // Serial.println(entradaSerial);
    servoActuar =
        entradaSerial.substring(3);
    // Serial.println(servoActuar);
}