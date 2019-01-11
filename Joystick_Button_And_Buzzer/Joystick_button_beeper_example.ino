/*
  ###Code Summary###
  作者:河謝工程師
  電子信箱:ejtx@arklab.tw
  日期：2019-01-07
  時間：16:42
  說明：遙控器範例程式碼，按下各別按鈕後由蜂鳴器能發出聲音
  1. 遙控器中間以八字排列的按鈕，使用類比A4針腳，故需要使用ADC進行讀取。
  2. 實際上並非一個蜂鳴器，而是可依照頻率發出聲音的喇巴。
  ###Code Summary###
*/

#define LEFT_BUMPER 2
#define RIGHT_BUMPER 4
#define BUZZER 9
#define LEFT_VR_X A0
#define LEFT_VR_Y A1
#define RIGHT_VR_X A2
#define RIGHT_VR_Y A3
#define ONE_PIN_BTN A4

void setup() {
  Serial.begin(115200);
  pinMode(RIGHT_BUMPER, INPUT);
  pinMode(LEFT_BUMPER, INPUT);
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
      tone(BUZZER, 2000); //可自行在此取代此行，寫入想要寫的程式碼
      button_id = 1;
      break;
    case 400 ... 420:
      tone(BUZZER, 2000);
      button_id = 2;
      break;
    case 330 ... 350:
      tone(BUZZER, 2000);
      button_id = 3;
      break;
    case 240 ... 260:
      tone(BUZZER, 2000);
      button_id = 4;
      break;
	case 760 ... 780:
      tone(BUZZER, 2000);
      button_id = 5;
      break;
	case 675 ... 695:
      tone(BUZZER, 2000);
      button_id = 6;
      break;
	case 605 ... 625:
      tone(BUZZER, 2000);
      button_id = 7;
      break;
    case 550 ... 570:
      tone(BUZZER, 2000);
      button_id = 8;
      break;
	case 135 ... 155:
      tone(BUZZER, 2000);
      button_id = 9;
      break;
    case 865 ... 885:
      tone(BUZZER, 2000);
      button_id = 10;
      break;
    default:
      if (digitalRead(LEFT_BUMPER) == LOW) {
        tone(BUZZER, 2000);
        button_id = 11;
      } else if (digitalRead(RIGHT_BUMPER) == LOW) {
        button_id = 12;
      } else {
        noTone(BUZZER);
      }
      break;
  }
  return button_id;
}
