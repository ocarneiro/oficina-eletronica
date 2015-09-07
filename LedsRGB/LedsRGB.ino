/*
 Experiencia com LED's RGB
 
 Hardware:
  - 3 potenciometros (marcados R, G e B)
  - 1 ou mais LED's RGB Catodo comum (perna grande = GND)
  - Arduino
 
 Funcionamento:
  - Cada potenciometro controla uma das cores do LED RGB
  - Ao movimentar o potenciometro R, aumenta-se a intensidade do vermelho;
  - Ao movimentar o potenciometro G, aumenta-se a intensidade do verde;
  - Ao movimentar o potenciometro B, aumenta-se a intensidade do azul.

 Conexoes:
  - Uma extremidade de cada potenciometro ao +5V
  - A outra extremidade de cada potenciometro ao GND
  - O sinal do potenciometro do R ligado aa porta A0 do Arduino
  - O sinal do potenciometro do G ligado aa porta A1 do Arduino
  - O sinal do potenciometro do B ligado aa porta A2 do Arduino
  - Perna comum do LED RGB conectada ao GND
  - Perna R do LED ligada ao pino 9
  - Perna G do LED ligada ao pino 10
  - Perna B do LED ligada ao pino 11
 
 criado em 07 set 2015, baseado no exemplo AnalogInOutSerial
 por Otavio Carneiro (carneiro.blog.br)
 
 Este codigo esta em dominio publico e pode ser obtido no github:
 https://github.com/ocarneiro/oficina-eletronica
 
 This code is in the public domain.
 
 */

const int pinoEntradaR = A0;
const int pinoEntradaG = A1;
const int pinoEntradaB = A2;

const int pinoSaidaR = 9;
const int pinoSaidaG = 10;
const int pinoSaidaB = 11;

void setup() {
  //inicializa a saida serial para debug
  Serial.begin(9600); 
  //inicializa os pinos de saida
  pinMode(pinoSaidaR, OUTPUT);
  pinMode(pinoSaidaG, OUTPUT);
  pinMode(pinoSaidaB, OUTPUT);
}

// Recebe o valor do potenciometro e ajusta a intensidade da cor
// de acordo com o valor recebido.
int lePotAcendeLed(int pinoEntrada, int pinoSaida) {
  // le o valor do potenciometro
  int valorEntrada = analogRead(pinoEntrada);
  // converte o valor lido para um valor de saida
  int valorSaida = map(valorEntrada, 0, 1023, 0, 255);  
  // ajusta a intensidade da cor do LED
  analogWrite(pinoSaida, valorSaida);           

  return valorEntrada;
}

void loop() {
  int r = lePotAcendeLed(pinoEntradaR, pinoSaidaR);
  delay(2);
  int g = lePotAcendeLed(pinoEntradaG, pinoSaidaG);
  delay(2);
  int b = lePotAcendeLed(pinoEntradaB, pinoSaidaB);
  delay(2);
  debug(r,g,b);
  delay(500);
}

void debug(int r, int g, int b) {
  Serial.print("R = ");
  Serial.print(r);
  Serial.print("G = ");
  Serial.print(g);
  Serial.print("B = ");
  Serial.print(b);
}
