#include <Servo.h>
 

//Inicializa as variaveis
int Vel = 10;
int Ajust = 15;
int D_Atual = 0;
int Sp = 0;
int P = 0;
int erro = 0;
int kp = 5;
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
  
  //Condiçoes e regras
  if(D_Atual>=16){
  RodaDir.write((90+Vel)-P);
  RodaEsq.write(90-Vel); 
  
  }
  else if(D_Atual<=14){
  RodaEsq.write((90-Vel)-P);
  RodaDir.write(90+Vel);
  }
  else 
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




