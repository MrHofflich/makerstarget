/*
Serial laser controller.
le'me: Eden Candelas
hsmty.org
*/

#include <Servo.h> 

#define LIMITEBAJO 60
#define LIMITEALTO 120
#define SERVOX 10
#define SERVOY 9
#define RETRASO_PASO 60
#define JOYSTICKX 1
#define JOYSTICKY 0
#define DELAY 50
#define CENTRO 0
#define IZQUIERDA -1
#define DERECHA 1
#define BUTTON 3
#define LASER 4



Servo servoY;  // create servo object to control a servo 
Servo servoX;  // create servo object to control a servo 
// El servo se mueve de 30 a 160 
int posicionServoY = 90; 
int posicionServoX = 90;
int presionado = 1;
long unsigned lastMillis; 

void setup() 
{ 
    Serial.begin(9600);
    Serial.println("[setup]:Init");
    servoY.attach(SERVOY);  // usando default
    servoY.write(posicionServoY);
    servoX.attach(SERVOX);  // usando default
    servoX.write(posicionServoX);

    pinMode(LASER, OUTPUT);

    digitalWrite(3, LOW);
    lastMillis = millis();
    digitalWrite(BUTTON, HIGH);
    attachInterrupt(0 , state, FALLING);
} 
 
 
void loop() 
{ 
    if (timer(DELAY)){
        int valorX = analogRead(JOYSTICKX);
        int pasoX = definirPaso(valorX);
        int direccionX = definirDireccion(valorX);
        int valorY = analogRead(JOYSTICKY);
        int pasoY = definirPaso(valorY);
        int direccionY = definirDireccion(valorY);

        posicionServoX = moveServoPasos(pasoX, servoX, valorX, posicionServoX, direccionX);
        posicionServoY = moveServoPasos(pasoY, servoY, valorY, posicionServoY, direccionY);
    }
    digitalWrite(LASER, presionado);



    // posicionServoY = moveServo(arrayPosicionesX[0], servoY, posicionServoY);
    // posicionServoX = moveServo(arrayPosicionesY[0], servoX, posicionServoX);
    // posicionServoY = moveServo(arrayPosicionesX[1], servoY, posicionServoY);
    // posicionServoX = moveServo(arrayPosicionesY[1], servoX, posicionServoX);
}

int moveServoPasos(int paso, Servo &servo, int valor, int posicionServo, int  direccion){
    
    if(direccion == CENTRO){
    //  continue;
    }else if(direccion == DERECHA){
        Serial.print("Posicion anterior anterior der: ");
        Serial.println(posicionServo);
        posicionServo = posicionServo + paso;
        servo.write(posicionServo);
        posicionServo = posicionServo;
            if(posicionServo > LIMITEALTO){posicionServo = LIMITEALTO;} 
    }else if(direccion == IZQUIERDA){
        Serial.print("Posicion anterior Yizq: ");
        Serial.println(posicionServo);
        posicionServo = posicionServo - paso;
        servo.write(posicionServo);
        posicionServo = posicionServo;
        if(posicionServo < LIMITEBAJO){posicionServo = LIMITEBAJO;} 
    }
    
    // Serial.println();
    return posicionServo;
}

int definirPaso(int valor){
    int paso=0;

    Serial.println("Valor: ");
    Serial.println(valor);

    if(valor > 500 && valor < 520){
        paso = 0;
    }else if((valor <= 500 && valor > 350) || (valor >= 520 && valor < 670)){
        paso = 1;
    }else if((valor <= 350 && valor > 200) || (valor >= 670 && valor < 820) ){
        paso = 2;
    }else if((valor <= 200 && valor > 125) || (valor >= 820 && valor < 895)){
        paso = 3;
    }else if((valor <= 125 && valor > 50) || (valor >= 895 && valor < 945)){
        paso = 5;
    }else if((valor <= 50 && valor >= 0 ) || (valor >= 900 && valor <= 1024 )){
        paso = 8;
    }else{
        Serial.println("-_-g");
        paso = 0;
    }

    Serial.print("Grados salida: ");
    Serial.println(paso);
    return paso;

}

int definirDireccion(int valor){
    int direccion;
    Serial.println("Direccion: ");
    if(valor <= 500){
        direccion = IZQUIERDA;
        Serial.println(direccion);
    }else if(valor >=530){
        direccion = DERECHA;
        Serial.println(direccion);
    }else {
        direccion = CENTRO;
        Serial.println(direccion);
    }

    return direccion;
}

int timer(int delay){
    long double millisec = millis();
    if ((millisec - lastMillis) > delay){
        lastMillis = millisec;
        return 1;
    }else{
        return 0;
    }
}

void state(){
	presionado = !presionado;
}
