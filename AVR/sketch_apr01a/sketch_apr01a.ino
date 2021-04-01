#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}
void loop(){
  bool latest[4] = {0, 0, 0, 0};
  bool old[4]    = {0, 0, 0, 0};

  while(true){
    //前フレーム情報をスワップ
    for(int i = 0; i < 4; i++){ old[i] = latest[i]; }

    //最新データを取得
    if(digitalRead(3) == LOW){ latest[0] = true; }
    else { latest[0] = false; }
    
    if(digitalRead(4) == LOW){ latest[1] = true; }
    else { latest[1] = false; }
    
    if(digitalRead(5) == LOW){ latest[2] = true; }
    else { latest[2] = false; }
    
    if(digitalRead(6) == LOW){ latest[3] = true; }
    else { latest[3] = false; }

    //出力
    if(latest[0] == true && old[0] == true) { Keyboard.press('a'); }
    else { Keyboard.release('a'); }

    if(latest[1] == true && old[1] == true) { Keyboard.press('b'); }
    else { Keyboard.release('b'); }

    if(latest[2] == true && old[2] == true) { Keyboard.press('c'); }
    else { Keyboard.release('c'); }

    if(latest[3] == true && old[3] == true) { Keyboard.press('d'); }
    else { Keyboard.release('d'); }
    delay(1); 
  }
}
