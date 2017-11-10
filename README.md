# Carro_Seguidor_de_Pared

Princípios de Controle

(Carro com sensor ultrassônico e infravermelho)

Dupla: Miltemberg Cesar Serpa e Luiz Sérgio Rocha Silva

Introdução

Em nosso projeto utilizamos dois sensores, um ultrassônico e o outro infravermelho, para fazer a medição da distância do carro até um determinado obstáculo. No caso, instalamos o sensor ultrassônico na lateral do carro e o infravermelho na ponta dianteira, como mostra a figura:
![Alt Text](https://github.com/luizdm/Carro_Seguidor_de_Parede/blob/master/imagens/CARRO1.jpg?raw=true)
A partir da captação da distância do carro até o obstáculo, conseguimos controlar a trajetória do carro fazendo com que ele mantenha uma distância desejada. No caso, faremos o carro percorrer um trajeto paralelo a uma parede, sempre mantendo uma distância determinada. Para fazer com que o carro mantenha a distância desejada, controlamos a velocidade das rodas traseiras, assim ele mantém a trajetória.

Utilizamos Sensor ultrassônico, Arduino como controlador e os motores como atuadores. Para a montagem do carro, utilizamos uma plaquinha de madeira, duas rodas, uma roda boba na dianteira do carro, fios para a conexão, protoboard e parafusos.
Fundamentação Teórica

Em nosso projeto, utilizamos alguns componentes para fazer com que ele funcione da maneira desejada, são eles: Arduino UNO, Sensor Ultrassônico, Sensor infravermelho, Motor de rotação e componentes elétricos e eletrônicos.

-Arduino
![Alt Text](https://github.com/luizdm/Carro_Seguidor_de_Parede/blob/master/imagens/ARDUINO.jpg?raw=true)


Utilizado para fazer o controle, através de programação, dos sensores e dos motores. Com ele regulamos a velocidade de rotação das rodas e a distância do carro até a parede.

-Sensor Ultrassônico
![Alt Text](https://github.com/luizdm/Carro_Seguidor_de_Parede/blob/master/imagens/SENSOR.jpg?raw=true)
O sensor ultrassônico envia sinais de ultrassom em uma frequência que não conseguimos ouvir. Quando o sinal encontra um obstáculo, ele rebate e retorna ao sensor. O tempo que o sinal leva para ir até o obstáculo e retornar é a base para podermos saber a distância entre o carro e o determinado objeto.

-Sensor Infravermelho
![Alt Text](https://github.com/luizdm/Carro_Seguidor_de_Parede/blob/master/imagens/SENSORINFRA.jpg?raw=true)
Tem o mesmo princípio de funcionamento do sensor ultrassônico, porém ao invés de ser enviado um sinal ultrassom, é enviado infravermelho. Com ele também conseguimos saber a distância.

-Motor de Rotação
![Alt Text](https://github.com/luizdm/Carro_Seguidor_de_Parede/blob/master/imagens/MOTOR.jpg?raw=true)
Faz com que as rodas traseiras girem, assim movimentando o carro. A velocidade e sentido das rodas é controlada pelo arduino.

Diagrama de Blocos

No sistema do nosso projeto, a variável de controle é a velocidade das rodas, fazendo assim o carro manter a direção e distância da parede. A saída do sistema é realimentada pelos sensores, com isso alterando a velocidade das rodas dependendo da distância do carro até a parede. O sistema tende a seguir a referência determinada na programação, ou seja, tende a manter a distância desejada. Com as características citadas a cima, podemos concluir que nosso sistema é de malha fechada, seguindo o diagrama abaixo:

Controlador Sistema

Distância Velocidade das rodas

Dispositivo de Medida

Programação
![Alt Text](https://github.com/luizdm/Carro_Seguidor_de_Parede/blob/master/imagens/CODE1.jpg?raw=true)

Através da programação do arduino, conseguimos definir os parâmetros para o nosso projeto, ou seja, determinamos a distância desejada e a velocidade das rodas traseiras.

Os pinos “trigger” e “echo”, são os responsáveis pelo envio e recepção dos sinais de ultrasson, fazendo com que determine a distância do carro ao obstáculo. Determinamos algumas variáveis necessárias, como por exemplo: velocidade e ajuste.
![Alt Text](https://github.com/luizdm/Carro_Seguidor_de_Parede/blob/master/imagens/image.png?raw=true)
Nessa parte do programa, é feita a leitura das informações que os sensores estão transmitindo, fazendo com que possamos determinar as condições para o motor girar as rodas em determinada velocidade.

Conclusão

Em nosso projeto conseguimos fazer o controle de um carro através do arduino, de motor e sensores, assim o fizemos percorrer um trajeto paralelo à parede e mantendo uma distância determinada. O arduino, podemos chamar de “cérebro” do sistema, pois, através de sua programação, podemos definir parâmetros desejados por nós, como a velocidade das rodas e a distância que queremos que ele mantenha da parece.

Esse projeto pode ser aplicado em pintura de faixas numa estrada, fazendo o carro percorrer a trajetória desejada e pintando a pista.

Para uma melhor eficiência de nosso projeto, podemos implementar mais sensores, na outra lateral e na dianteira do carro, por exemplo, fazendo com que o carro possa ter uma melhor eficiência no controle dos obstáculos ao seu redor, assim evitando colisão.
