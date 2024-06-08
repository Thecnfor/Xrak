void setup() {  
  Serial.begin(115200);
}  

void loop() {  
  // 读取串口数据直到遇到换行符  
  if (Serial.available()) {  
    String data = "";  
    while (Serial.available()) {  // 读取所有字节直到遇到换行符  
      if (Serial.peek() == '\n') {  // 如果遇到换行符，则停止读取  
        break;  
      }  
      data += (char)Serial.read();  // 读取一个字节并转换为字符  
    }  
    // 解析数据  
    if (data.endsWith("_control")) {  
      // 提取action  
      String action = data.substring(0, data.length() - 8); // 移除"_control"部分  
      // 根据需要转为小写或大写（如果需要的话）  
      action.toLowerCase(); // 或者 action.toUpperCase();  
      // 打印或处理action  
      Serial.print("Action: ");  
      Serial.println(action);  
    } else {  
      String data = Serial.readStringUntil('\n');
      // 使用逗号作为分隔符来分割字符串  
      int commaIndex = data.indexOf(',');  
      if (commaIndex != -1) { // 确保找到了逗号  
      int x = data.substring(0, commaIndex).toInt(); // 提取x值  
      int y = data.substring(commaIndex + 1).toInt(); // 提取y值  
      
      // 这里可以对x和y值进行进一步的处理或输出  
      Serial.print("Received x: ");  
      Serial.print(x);  
      Serial.print(", y: ");  
      Serial.println(y);  
      }  
    }  
  delay(10);
  }
}