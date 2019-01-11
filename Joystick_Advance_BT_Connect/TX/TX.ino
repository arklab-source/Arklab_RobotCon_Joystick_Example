/*
  ###CodeSummary###
  作者:河謝工程師
  電子信箱:ejtx@arklab.tw
  日期：2019-01-07
  時間：16:42
  說明：遙控器範例程式碼，按下各別按鈕後由蜂鳴器能發出聲音
  1.遙控器中間以八字排列的按鈕，使用類比A4針腳，故需要使用ADC進行讀取。

  ###Code Summary###
*/
#define LEFT_BUMPER 2
#define RIGHT_BUMPER 4
#define BUZZER 9
#define LEFT_VR_X A0
#define LEFT_VR_Y A1
#define RIGHT_VR_X A2
#define RIGHT_VR_Y A3
#define ONE_PIN_BUTTON A4
#define PACKET_HEADER "!A"
#define DIRECTION ">"
#define CMD_CODE "C"
#define PACKET_STANDARD_HEADER "!A>C"
#define PACKET_SIZE 7
#define PACKET_NEWLINE "\r\n"
#define DEBUG_MODE false
#define RC_Hz 10
#define RC_CMD_INTERVAl 1000/RC_Hz
#define HIGH_ADC_Resoultion true

unsigned long previousMillis = 0;
void setup() {
  // put your setup code here,to run once:
  Serial.begin(115200);
  Serial.print(PACKET_STANDARD_HEADER);
  pinMode(LEFT_BUMPER, INPUT);
  pinMode(RIGHT_BUMPER, INPUT);
  pinMode(ONE_PIN_BUTTON, INPUT);
}
void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= RC_CMD_INTERVAl) {
    previousMillis = currentMillis;
    int lvx = analogRead(LEFT_VR_X);
    int rvx = analogRead(RIGHT_VR_X);
    int lvy = analogRead(LEFT_VR_Y);
    int rvy = analogRead(RIGHT_VR_Y);
    int lb = digitalRead(LEFT_BUMPER);
    int rb = digitalRead(RIGHT_BUMPER);
    int opb = analogRead(ONE_PIN_BUTTON);
    if (HIGH_ADC_Resoultion & DEBUG_MODE) {
      Serial.print(PACKET_STANDARD_HEADER);
      Serial.print(",");
      Serial.print(lvx);
      Serial.print(",");
      Serial.print(lvy);
      Serial.print(",");
      Serial.print(rvx);
      Serial.print(",");
      Serial.print(rvy);
      Serial.print(",");
      Serial.print(opb);
      Serial.print(",");
      Serial.print(!lb);
      Serial.print(",");
      Serial.print(!rb);
      Serial.write(PACKET_NEWLINE);

    } else if (HIGH_ADC_Resoultion & !DEBUG_MODE) {
      Serial.print(PACKET_STANDARD_HEADER);
      Serial.write(0x07);
      SerialWrile2Byte(lvx);
      SerialWrile2Byte(lvy);
      SerialWrile2Byte(rvx);
      SerialWrile2Byte(rvy);
      SerialWrile2Byte(opb);
      Serial.write(!lb);
      Serial.write(!rb);
      Serial.write((lvx + rvx + opb + !rb) % 255);
      Serial.write(PACKET_NEWLINE);

    } else if (!HIGH_ADC_Resoultion & DEBUG_MODE) {
      Serial.print(PACKET_STANDARD_HEADER);
      Serial.write(0x07);
      Serial.write(lvx);
      Serial.write(lvy);
      Serial.write(rvx);
      Serial.write(rvy);
      Serial.write(opb);
      Serial.write(!lb);
      Serial.write(!rb);
      Serial.write((lvx + rvx + opb + !rb) % 255);
      Serial.write(PACKET_NEWLINE);
      
    }
  }
}
void SerialWrile2Byte(int value) {
  Serial.write(highByte(value));
  Serial.write(lowByte(value));
}
