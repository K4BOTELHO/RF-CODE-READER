// Lógica para ler códigos RF dos produtos da HAWK
// Por Kawê Botelho

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);                // Inicializa a Serial

  // Configura o receptor RF usando a interrupção 0 (pino D2 no Arduino)
  mySwitch.enableReceive(0);           // 0 → Interrupt 0 → D2
}

void loop() {
  // Verifica se há dados RF disponíveis
  if (mySwitch.available()) {
    unsigned long codigoRF = mySwitch.getReceivedValue();

    if (codigoRF == 0) {
      Serial.println("Código desconhecido ou erro na recepção.");
    } else {
      Serial.print("Código RF recebido: ");
      Serial.print(codigoRF);
      Serial.print(" | Bits: ");
      Serial.println(mySwitch.getReceivedBitlength());
    }

    mySwitch.resetAvailable();  // Limpa para próxima recepção
  }
}
