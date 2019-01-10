/*
  ###Code Summary###
  作者: Jack
  電子信箱: wwin3286tw@yahoo.com.tw
  日期：2019-01-07
  時間：16:42
  說明：遙控器範例程式碼，按下各別按鈕後由蜂鳴器能發出聲音
  1. 遙控器中間以八字排列的按鈕，使用類比A4針腳，故需要使用ADC進行讀取。

  ###Code Summary###
*/

#define LEFT_BTN_1 2
#define RIGHT_BTN_1 4
#define BEEPER 9
#define LEFT_VR_X A0
#define LEFT_VR_Y A1
#define RIGHT_VR_X A2
#define RIGHT_VR_Y A3
#define ONE_PIN_BTN A4

void setup() {
  Serial.begin(115200);
  pinMode(RIGHT_BTN_1, INPUT);
  pinMode(LEFT_BTN_1, INPUT);
}


void loop() {
  int val = analogRead(ONE_PIN_BTN);
  int lvx = analogRead(LEFT_VR_X);
  int rvx = analogRead(RIGHT_VR_X);
  int lvy = analogRead(LEFT_VR_Y);
  int rvy = analogRead(RIGHT_VR_Y);
  Serial.println(getClickButton());
}
int getClickButton() {
  int val = analogRead(ONE_PIN_BTN);
  int button_id = 0;
  switch (val) {
    case 450 ... 470:
      tone(BEEPER, 2000);
      button_id = 1;
      break;
    case 400 ... 420:
      tone(BEEPER, 2000);
      button_id = 2;
      break;
    case 330 ... 350:
      tone(BEEPER, 2000);
      button_id = 3;

      break;
    case 240 ... 260:
      tone(BEEPER, 2000);
      button_id = 4;
      break;
    case 550 ... 570:
      tone(BEEPER, 2000);
      button_id = 8;
      break;
    case 605 ... 625:
      tone(BEEPER, 2000);
      button_id = 7;
      break;
    case 675 ... 695:
      tone(BEEPER, 2000);
      button_id = 6;
      break;
    case 760 ... 780:
      tone(BEEPER, 2000);
      button_id = 5;
      break;
    case 865 ... 885:
      tone(BEEPER, 2000);
      button_id = 10;
      break;
    case 135 ... 155:
      tone(BEEPER, 2000);
      button_id = 9;
      break;
    default:
      if (digitalRead(LEFT_BTN_1) == LOW) {
        tone(BEEPER, 2000);
        button_id = 11;
      } else if (digitalRead(RIGHT_BTN_1) == LOW) {
        button_id = 12;
      } else {
        // button_id = 0;
        noTone(BEEPER);
      }
      break;
  }
  return button_id;
}
