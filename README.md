# Sistema de Leitura de Códigos RF

Este projeto foi desenvolvido para realizar a leitura e identificação de sinais RF (Rádio Frequência) emitidos por produtos que tem essa tecnologia. A implementação foi realizada utilizando a biblioteca **RCSwitch** em um ambiente Arduino, garantindo confiabilidade e precisão na recepção dos sinais.

## 🎯 Objetivo

Permitir a captura de códigos RF, facilitando a análise, decodificação e integração de dispositivos com sistemas automatizados e embarcados.

## 🛠️ Tecnologias Utilizadas

- **Arduino NANO** ou compatível
- **Biblioteca RCSwitch** para comunicação RF
- **Receptor RF 433 MHz**
  
## ⚙️ Funcionamento

1. **Inicialização da Serial**: Comunicação estabelecida via `Serial.begin(115200)` para exibir os dados capturados.
2. **Configuração do Receptor RF**: Utilização da interrupção 0 (pino D2) para leitura eficiente dos sinais de rádio frequência.
3. **Loop de Operação**:
   - Verifica se há novos sinais RF disponíveis.
   - Se houver, imprime no monitor serial o código recebido e a quantidade de bits.
   - Caso haja erro na recepção, exibe uma mensagem de falha.

## 📝 Estrutura do Código

```cpp
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(0);  // Interrupção 0 → Pino D2
}

void loop() {
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

    mySwitch.resetAvailable();
  }
}
```

## ✅ Benefícios

- **Simplicidade**: Código limpo e objetivo para fácil integração em outros sistemas.
- **Eficiência**: Utiliza interrupções para garantir captura precisa dos sinais.
- **Versatilidade**: Pode ser adaptado para diferentes protocolos RF.

## 👨‍💻 Autor

Desenvolvido por **Kawê Botelho**.

---
