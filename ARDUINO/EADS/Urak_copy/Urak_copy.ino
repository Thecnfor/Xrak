void setup() {  
  Serial.begin(115200); // 确保Arduino A和Arduino B的波特率设置一致  
}  
  
void loop() {  
  if (Serial.available() > 0) {  
    String command = Serial.readStringUntil('\n'); // 读取一行数据直到遇到换行符  
    if (command == "TURN_ON") { // 检查指令是否为TURN_ON  
      Serial.println("LED turned on"); // 发送响应消息到串行监视器（如果连接了）  
    } else if (command == "turnOff") {  
      // 执行相应的操作，如关闭LED等  
      Serial.println("LED turned off"); // 发送响应消息到串行监视器（如果连接了）  
    }  
  }  
}