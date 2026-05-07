#include <Arduino.h>

int velocidade = 0; // Começa com o motor parado
bool ultimoEstadoBotao = LOW; 

void setup() {
  pinMode(2, INPUT);  // Pino do botão (D2)
  pinMode(9, OUTPUT); // Pino do motor (D9) - PWM
}

void loop() {
  // Lê se o botão está apertado (HIGH)
  bool estadoAtualBotao = digitalRead(2);

  // Lógica para detectar apenas o momento em que você APERTA (subida)
  if (estadoAtualBotao == HIGH && ultimoEstadoBotao == LOW) {
    velocidade = velocidade + 64; // Aumenta a velocidade (em degraus)

    if (velocidade > 255) {
      velocidade = 0; // Se passar do máximo, volta a zero (para o motor)
    }

    analogWrite(9, velocidade); // Envia o sinal para o motor rodar
    delay(50); // Debounce para evitar cliques duplos falsos
  }

  ultimoEstadoBotao = estadoAtualBotao;
}