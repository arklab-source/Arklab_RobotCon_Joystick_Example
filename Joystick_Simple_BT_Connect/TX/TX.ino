void setup() {
  Serial.begin(115200); //啟用序列，速度115200 bps
}

void loop() { 
  //讀取使用者輸入，然後寫入
  //可以嘗試在終端機上輸入beep，若有連接，則蜂鳴器響起
  if (Serial.available() > 0) {
    Serial.write(Serial.read()); 
  }
}
