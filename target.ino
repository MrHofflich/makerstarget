int sensor = 4;
int puntos = 13;
int golpe10Puntos;
int valor;


void setup() {
  // put your setup code here, to run once:
 pinMode(puntos,OUTPUT);
 Serial.begin(9600);
 digitalWrite(puntos,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
 valor = analogRead(sensor);
 if (valor >=700) {
 
   golpe10Puntos = valor/4;
   digitalWrite(puntos,HIGH);
   Serial.print(golpe10Puntos);
   Serial.print(" , ");
   Serial.println("Encendido");
   delay(100);
 }
 
 if(valor <= 500) {
   digitalWrite(puntos,LOW);
   Serial.print(valor);
   Serial.print(" , ");
   Serial.println("Apagado");
   delay(100);
 }
}
