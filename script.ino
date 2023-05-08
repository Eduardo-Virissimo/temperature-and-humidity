// Biblioteca Sensor de Temperatura
#include "DHTesp.h"

// Pino digital para a conexão no ESP32
const int DHT_PIN = 15;

// Importação do DHTesp
DHTesp dhtSensor;

void setup() {
  Serial.begin(115200);

  //Pegando a importação e definindo um pino / modelo (no caso, DHT22)
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  //Definindo pinos como saída
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  
  //Puxando os valores de temperatura e umidade
  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  //Caso a temperatura ultrapasse 35°C
  if(data.temperature >= 35){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  //Caso a umidade ultrapasse 70%
  if(data.humidity >=	70){
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  
  Serial.println("|  Temperatura atual: " + String(data.temperature, 1) + "°C    |");
  Serial.println("|     Umidade atual: " + String(data.humidity, 1) + "%      |");
  Serial.println("<------------------------------->");
  
  //Intervalo de 5 segundos solicitado pela SA
  delay(5000);
}