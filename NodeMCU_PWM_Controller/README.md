## 1. Introdução ao PWM
O **PWM (Pulse Width Modulation)** é uma técnica utilizada para controlar a quantidade de energia enviada a uma carga eletrônica. Ao variar o "Duty Cycle" (tempo que o sinal permanece em nível alto), conseguimos simular tensões intermediárias, permitindo controlar a velocidade do motor de 0% a 100%.

## 2. Componentes Necessários
* **Microcontrolador:** NodeMCU V3 (ESP8266).
* **Driver de Motor:** L293D (Ponte H).
* **Atuador:** Motor DC.
* **Entrada:** Botão Pulsador (Push-button).
* **Resistor:** 10kΩ (para o botão).
* **Fonte de Alimentação:** Bateria de 5V ou similar.
* **Instrumentação:** Osciloscópio (para visualização da onda PWM no simulador).

## 3. Esquemático
O circuito foi projetado no Proteus, conectando o NodeMCU ao driver L293D para isolar a potência do motor da lógica do microcontrolador.

> **Nota:** Certifique-se de que o GND (terra) da fonte externa e o GND do NodeMCU estejam conectados (GND Comum).

## 4. Código-fonte
O código utiliza a função `analogWrite()` para enviar o sinal PWM ao pino de controle.

```cpp
#include <Arduino.h>

const int pinoBotao = 2;   
const int pinoMotor = 9;   

int velocidade = 0; 
bool ultimoEstadoBotao = LOW; 

void setup() {
  pinMode(pinoBotao, INPUT);  
  pinMode(pinoMotor, OUTPUT); 
}

void loop() {
  bool estadoAtualBotao = digitalRead(pinoBotao);

  if (estadoAtualBotao == HIGH && ultimoEstadoBotao == LOW) {
    velocidade = velocidade + 64; 

    if (velocidade > 255) {
      velocidade = 0;
    }

    analogWrite(pinoMotor, velocidade); 
    delay(50); 
  }

  ultimoEstadoBotao = estadoAtualBotao;
}
## 6. Funcionamento do Projeto
Ao ligar, o motor inicia parado (velocidade = 0).

A cada pressão no botão, a variável velocidade aumenta em 64 unidades (aproximadamente 25% do ciclo de trabalho).

Os estados são: Parado -> 25% -> 50% -> 75% -> 100% -> Parado.

O osciloscópio no simulador permite visualizar a largura do pulso aumentando conforme a velocidade sobe.