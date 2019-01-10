#define BEEPER 9
void setup() {
  Serial.begin(115200); //啟用序列，速度115200 bps
}
String data="";
void loop() {
  //只做讀取，由於占用了硬體Serial，故在此範例請勿使用Serial.write()或Serial.print()等方法
  //以避免通訊風暴
  if (Serial.available() > 0) {
     data = Serial.readString();
     data.trim();
    // Serial.print(data);
    if (data == "beep") {
      tone(BEEPER,1000,500);
      data="";
    }
  }
}
