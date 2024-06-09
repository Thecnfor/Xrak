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
  static int currentX = 0 , currentY = 0;
  static bool motorXRunnig = false, motorYRunning = false;
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
        int newX = xStr.toInt();    
        int newY = yStr.toInt();    
        if (newX != currentX) {    
          currentX = newX;   
          motorXRunnig = true;
        }
        if (newY != currentY) {    
          currentY = newY;   
          motorYRunning = true;
        }
      } else {    
        Serial.println("数据错误=" + inputMessage);    
      }    
    }    
  }    
  if (motorXRunnig) {
      if (currentX > 0) {
          while (currentX > 0) {
              digitalWrite(P1_DIR_PIN, HIGH); // 设置方向  
              digitalWrite(P1_PUL_PIN, HIGH);
              delayMicroseconds(10);
              digitalWrite(P1_PUL_PIN, LOW);
              delay(STEP_DELAY);
          }
    } else {
          while (currentX < 0) {
              digitalWrite(P1_DIR_PIN, LOW); // 设置方向  
              digitalWrite(P1_PUL_PIN, HIGH);
              delayMicroseconds(10);
              digitalWrite(P1_PUL_PIN, LOW);
              delay(STEP_DELAY);
          }
  }
    motorXRunning = false; // 停止X轴电机  
    currentX = 0; // 重置当前X轴目标位置  
  }
    if (motorYRunning) {
      if (currentY > 0) {
          while (currentY > 0) {
              digitalWrite(P2_DIR_PIN, HIGH); // 设置方向  
              digitalWrite(P2_PUL_PIN, HIGH);
              delayMicroseconds(10);
              digitalWrite(P2_PUL_PIN, LOW);
              delay(STEP_DELAY);
          }
      } else {
          while (currentY < 0) {
              digitalWrite(P2_DIR_PIN, LOW); // 设置方向  
              digitalWrite(P2_PUL_PIN, HIGH);
              delayMicroseconds(10);
              digitalWrite(P2_PUL_PIN, LOW);
              delay(STEP_DELAY);
        }
      }
      motorYRunning = false; // 停止Y轴电机  
      currentY = 0; // 重置当前Y轴目标位置 
    }
}