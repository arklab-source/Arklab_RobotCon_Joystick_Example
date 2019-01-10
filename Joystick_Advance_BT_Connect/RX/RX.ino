String inputString = "";
#define LEFT_BTN_1 2
bool stringComplete = false;
int pv = 0;
int val = 0;
int hz = 0;

int lvx = 0;
int rvx = 0;
int lvy = 0;
int rvy = 0;
int lb = 0;
int rb = 0;
int opb = 0;


void setup() {
  Serial.begin(115200);
  Serial.println("Printer");
}
byte rc_data[19];
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
void loop() {
  serialEvent();
  if (stringComplete) {
    string header[5];
    
   // inputString.toCharArray(header, sizeof(header));
    Serial.print(header);
    inputString = "";
    stringComplete = false;
  }

}
