#include <Servo.h>
 

//Inicializa as variaveis
int Vel;
float temp=0;
float tempA=0;
int Sp = 15;
int P = 0;
int I = 0;
int D = 0;
float erro = 0;
float Dt = 0;
float Derro = 0;
int kp = 15;
int ki = 0.002;
int kd = 10;
int distance;
long duration;
int trigPin=4;
int echoPin=5;

Servo RodaDir,RodaEsq;
 
 
 //Configura os pinos
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); //salida del pulso generado por el sensor ultrasónico
  pinMode(echoPin, INPUT);//entrada del pulso generado por el sensor ultrasónico
  RodaDir.attach(8);
  RodaEsq.attach(9);
  temp = tempA;
  tempA = millis();
  Dt=tempA-temp;
  
}
 
void loop()
{
  //Le as informacoes dos sensores
  us();
  erro= Sp-distance;
  P=kp*erro;
  I=I+(ki*erro*Dt);
  D=kd*(Derro/Dt);
  Vel = 10 + (P + I + D);
  
  RodaDir.write(90+Vel);
  RodaEsq.write(90-Vel); 
}
  void us() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.println(Vel);
}
