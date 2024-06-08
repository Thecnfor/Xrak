void setup() {  
  Serial.begin(115200); // 设置串行通信波特率为9600  
}  
  
void loop() {  
  if (Serial.available() > 0) { // 检查是否有数据可读  
    String command = Serial.readStringUntil('\n'); // 读取一行数据  
    if (command == "TURN_ON") { // 检查指令是否为TURN_ON  
      // 执行相应的操作，如打开LED等  
      digitalWrite(LED_PIN, HIGH); // 假设LED_PIN已定义并连接到LED  
    }  
  }  
}