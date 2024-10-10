#include <Arduino.h>
#include <KeyPad.h>

const byte Linhas = 4;
const byte Colunas = 4;

const char teclas_matriz[Linhas][Colunas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const byte pinos_linhas[Linhas] = {9, 8, 7, 6};
const byte pinos_colunas[Colunas] = {5, 4, 3, 2};

Keypad teclado_personalizado = Keypad(makeKeymap(teclas_matriz), pinos_linhas, pinos_colunas, Linhas, Colunas);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char leitura_teclas = teclado_personalizado.getKey();

  if(leitura_teclas){
    Serial.println(leitura_teclas);
  }
}

