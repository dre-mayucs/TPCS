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
  }

  Serial.print("0 : フォトトランジスタ値 : ");
  Serial.println(D_Data[0]);
  Serial.print("1 : フォトトランジスタ値 : ");
  Serial.println(D_Data[1]);
  Serial.print("2 : フォトトランジスタ値 : ");
  Serial.println(D_Data[2]);
  Serial.print("3 : フォトトランジスタ値 : ");
  Serial.println(D_Data[3]);
  Serial.println();

  /*if(AA < 200){
    Keyboard.press(0x61);
    }
    else{
    Keyboard.release(0x61);
    }

    if(AB < 5){
    Keyboard.press(0x62);
    }
    else{
    Keyboard.release(0x62);
    }

    if(AC < 5){
    Keyboard.press(0x63);
    }
    else{
    Keyboard.release(0x63);
    }*/
  delay(1);
}
