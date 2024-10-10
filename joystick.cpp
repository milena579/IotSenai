#include <Arduino.h>

int x = A0; 
int y = A1; 
int botao = 2;
char modo;

void leitura() {
  for (int i = 0; i < 10; i++) { 
    Serial.print("Leitura do eixo X: ");
    Serial.println(analogRead(x));
    Serial.print("Leitura do eixo Y: ");
    Serial.println(analogRead(y));
    Serial.print("Leitura do botão: ");
    Serial.println(digitalRead(botao));
    Serial.println("------------------");
    delay(500);
  }
}

void movimento() {
  for (int j = 0; j < 10; j++) { 
    if ((analogRead(x)) == 0) {
      Serial.println("Bastão movimentado para baixo");
    }
    if ((analogRead(x)) == 1023) {
      Serial.println("Bastão movimentado para cima");
    }
    if ((analogRead(y)) == 0) {
      Serial.println("Bastão movimentado para esquerda");
    }
    if ((analogRead(y)) == 1023) {
      Serial.println("Bastão movimentado para direita");
    }
    if ((digitalRead(botao)) == 0) {
      Serial.println("Botão pressionado");
    }
    if ((digitalRead(botao)) == 1) {
      Serial.println("Botão solto");
    }
    Serial.println("------------------");
    delay(500);
  }
}

void setup() {
  Serial.begin(9600); 
  pinMode(botao, INPUT_PULLUP); 
}

void loop() {
  if (Serial.available()) { 
    modo = Serial.read(); 
    Serial.println(modo); 
  }
 
  switch (modo) {
    case 'A':
      leitura(); 
      break;

    case 'B':
      movimento(); 
      break;
  }
}
