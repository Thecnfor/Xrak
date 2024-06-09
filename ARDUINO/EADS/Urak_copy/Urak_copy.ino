
void setup() {  
  Serial.begin(115200);  
}  
  
void loop() {  
if (Serial.available() > 0) {  
String inputMessage = Serial.readStringUntil('\n');
  if (inputMessage.startsWith("Control_")) {
    String result = inputMessage.substring(strlen("Control_")); // 去掉前缀
    Serial.println(result);
  }else {
     int inputIndex = inputMessage.indexOf(",");
     if (inputIndex != -1) {
       String xStr = inputMessage.substring(0, inputIndex);
      String yStr = inputMessage.substring(inputIndex + 1);
      int x = xStr.toInt();
       int y = yStr.toInt();
      Serial.println("x=" + String(x) + ", y=" + String(y));
    }else {
      Serial.println("数据错误=" + inputMessage);
    }}
  }
}