#include "Keyboard.h"

void setup() {
  Serial.begin(250000);
  Keyboard.begin();

  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

void loop() {
  bool D_Data[4] = {0, 0, 0, 0};

  for(auto i = 3; i <= 6; i++){
    D_Data[i - 3] = digitalRead(i);

    Serial.print(i - 3);
    Serial.print(" : フォトトランジスタ値 : ");
    Serial.println(i - 3);
  }
  Serial.println();
  delay(1);
}
