#define ENA_PIN 13
#define P1_PUL_PIN 8
#define P2_PUL_PIN 4
#define P1_DIR_PIN 12
#define P2_DIR_PIN 7
#define STEP_DELAY 5

void setup() {  
  Serial.begin(115200);  
  pinMode(ENA_PIN, OUTPUT);
  pinMode(P1_PUL_PIN, OUTPUT);
  pinMode(P2_PUL_PIN, OUTPUT);
  pinMode(P1_DIR_PIN, OUTPUT);
  pinMode(P2_DIR_PIN, OUTPUT);
  digitalWrite(ENA_PIN, LOW);
}  

void loop() {      
  if (Serial.available() > 0) {      
    String inputMessage = Serial.readStringUntil('\n');    
    if (inputMessage.startsWith("Control_")) {    
      String result = inputMessage.substring(8);  
      if (result.startsWith("TURN_ON")) {
        digitalWrite(ENA_PIN, HIGH);
      } else if (result.startsWith("TURN_OFF")) {
        digitalWrite(ENA_PIN, LOW);
      }
        digitalWrite(ENA_PIN, HIGH);    
    } else if (inputMessage.startsWith("M")) {    
      String command = inputMessage.substring(4);  
      int inputIndex = command.indexOf(",");    
      if (inputIndex != -1) {    
        String xStr = command.substring(0, inputIndex);    
        String yStr = command.substring(inputIndex + 1);    
        int x = xStr.toInt();    
        int y = yStr.toInt();    
        if (x > 10) {
            digitalWrite(P1_DIR_PIN, HIGH);
            digitalWrite(P1_PUL_PIN, HIGH);
            delayMicroseconds(10);
            digitalWrite(P1_PUL_PIN, LOW);
            delay(STEP_DELAY);
        } else if (x < -10) {
            digitalWrite(P1_DIR_PIN, LOW);
            digitalWrite(P1_PUL_PIN, HIGH);
            delayMicroseconds(10);
            digitalWrite(P1_PUL_PIN, LOW);
            delay(STEP_DELAY);
        } else if (y > 10) {
            digitalWrite(P2_DIR_PIN, HIGH);
            digitalWrite(P2_PUL_PIN, HIGH);
            delayMicroseconds(10);
            digitalWrite(P2_PUL_PIN, LOW);
            delay(STEP_DELAY);
        } else if (y < -10) {
            digitalWrite(P2_DIR_PIN, LOW);
            digitalWrite(P2_PUL_PIN, HIGH);
            delayMicroseconds(10);
            digitalWrite(P2_PUL_PIN, LOW);
            delay(STEP_DELAY);
        }
      } else {    
        Serial.println("数据错误=" + inputMessage);    
      }    
    }    
  }    
}