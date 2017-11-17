#include <Servo.h>
 

//Inicializa as variaveis
int Vel;
int D_Atual = 0;
int Sp = 15;
int P = 0;
int I = 0;
int D = 0;
float erro = 0;
float Dt = 0;
float Derro = 0;
int kp = 20;
int ki = 0;
int kd = 0;
long dis;
long tem;
int trigger=4;
int eco=5;

Servo RodaDir,RodaEsq;
 
 
 //Configura os pinos
void setup()
{
  pinMode(10, OUTPUT); //salida del pulso generado por el sensor ultrasónico
  pinMode(9, INPUT);//entrada del pulso generado por el sensor ultrasónico
  pinMode(11, INPUT);//alarma de la distancia(encenderá el led)
  RodaDir.attach(8);
  RodaEsq.attach(9);
  
}
 
void loop()
{
  //Le as informacoes dos sensores
  us();
  erro= Sp-D_Atual;
  P=kp*erro;
  I=I+(ki*erro*Dt);
  D=kd*(Derro/Dt);
  Vel = 15 + (P + I + D);
  
  RodaDir.write(90+Vel);
  RodaEsq.write(90-Vel); 
}
  
 void us(){
    digitalWrite(trigger,LOW);//recibimiento del pulso.
    delayMicroseconds(5);
    digitalWrite(trigger, HIGH);//envió del pulso.
    delayMicroseconds(10);
    digitalWrite(trigger,LOW);
    tem=pulseIn(eco, HIGH);//fórmula para medir el pulso entrante.
    D_Atual= long(0.017*tem);//fórmula para calcular la distancia del sensor ultrasónico.
}

