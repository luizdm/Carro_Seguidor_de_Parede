#include <Servo.h>
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa as variaveis
Ultrasonic ultrasonic(pino_trigger, pino_echo);
int led = 13;
int Vel = 10;
int Ajust = 15;
int SensF = 0;
int SensL = 0;
int DistF = 0;
int DistL = 0;
Servo RodaDir,RodaEsq;
 
 
 //Configura os pinos
void setup()
{
  pinMode(led,OUTPUT);
  RodaDir.attach(8);
  RodaEsq.attach(9);
  
}
 
void loop()
{
  //Le as informacoes dos sensores
  digitalWrite(led,HIGH);
  float SensL;
  long microsec = ultrasonic.timing();
  SensL = ultrasonic.convert(microsec, Ultrasonic::CM);
  SensF = analogRead(DistF);
  
  //Condiçoes e regras
  if(SensL>=16){
  RodaDir.write((90+Vel)+Ajust);
  RodaEsq.write(90-Vel); 
  
  }
  else if(SensL<=14){
  RodaEsq.write((90-Vel)-Ajust);
  RodaDir.write(90+Vel);
  
  }
  else if(SensF<=25){
  RodaEsq.write((90-Vel)-Ajust);
  RodaDir.write(90);
  
  }
  else 
  RodaDir.write(90+Vel);
  RodaEsq.write(90-Vel);
  }
  




