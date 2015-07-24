int sensor = 4;
int sensor2 = 5;
int sensor3 = 3;
int sensor4 = 2;

int puntos = 13;


int golpe1Puntos;
int golpe2Puntos;
int golpe3Puntos;
int golpe4Puntos;

int valor;
int valor2;
int valor3;
int valor4;

void setup() {
  // put your setup code here, to run once:
 pinMode(puntos,OUTPUT);

 Serial.begin(9600);
 digitalWrite(puntos,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
 valor = analogRead(sensor);
 valor2 = analogRead(sensor2);
 valor2 = analogRead(sensor2);
 valor2 = analogRead(sensor2);
 
 if (valor >=401) {
   digitalWrite(puntos,HIGH);
   Serial.print(valor);
   Serial.print(" , ");
   Serial.println("Encendido");
   delay(100);
 }else if(valor <= 400) {
   digitalWrite(puntos,LOW);
   Serial.print(valor);
   Serial.print(" , ");
   Serial.println("Apagado");
   delay(100);
 }
 
 if(valor2 >= 700) {
   digitalWrite(puntos,HIGH);
   Serial.print(valor2);
   Serial.print(" , ");
   Serial.println("Encendido");
   
 } else if(valor2 <=500) {
   digitalWrite(puntos,LOW);
   Serial.print(valor2);
   Serial.print(" , ");
   Serial.println("Apagado");
 }
 
  if(valor3 >= 700) {
   digitalWrite(puntos,HIGH);
   Serial.print(valor3);
   Serial.print(" , ");
   Serial.println("Encendido");
   
 } else if(valor3 <=500) {
   digitalWrite(puntos,LOW);
   Serial.print(valor3);
   Serial.print(" , ");
   Serial.println("Apagado");
 }
 
   if(valor4 >= 700) {
   digitalWrite(puntos,HIGH);
   Serial.print(valor4);
   Serial.print(" , ");
   Serial.println("Encendido");
   
 } else if(valor4 <=500) {
   digitalWrite(puntos,LOW);
   Serial.print(valor4);
   Serial.print(" , ");
   Serial.println("Apagado");
 }
}
