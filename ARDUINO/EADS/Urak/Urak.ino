#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ESP8266WebServer.h>  
  
ESP8266WebServer server(80);  
  
const char* ssid = "HUAWEI-W";  
const char* password = "W@18025693031";  

void handleRoot() {  
  server.send(200, "text/plain", "这里可不该来，或者以后再来就有惊喜。");
}  

void setup() {  
  Serial.begin(115200);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);  
    Serial.print(".");  
  }
  Serial.println("");  
  Serial.println("WiFi connected");  
    
  server.on("/", handleRoot);  
  server.begin();  
  Serial.println("Server started");  

  server.on("/command", handleCommand); // 添加新的路由  
}  
  
void loop() {  
  server.handleClient();
}
  
void handleCommand() {  
  if (server.hasArg("action")) {  
    String action = server.arg("action");  
    if (action.equals("turnOn")) {  
      Serial.println("Control_TURN_ON"); // 简化为一个println调用  
      server.send(200, "text/plain", "读取成功 action=" + action);  
    } else if (action.equals("turnOff")) {  
      Serial.println("Control_TURN_OFF"); // 简化为一个println调用  
      server.send(200, "text/plain", "读取成功 action=" + action);  
    }  
  }  
  if (server.hasArg("x") && server.hasArg("y")) {  
    String x = server.arg("x");  
    String y = server.arg("y");  
    Serial.println("MOVE" + x + "," + y); // 移除/ln，添加换行符可以用println或print+"\n"
    server.send(200, "text/plain", "读取成功 x=" + x + ", y=" + y);  
  }  
  // 如果没有找到任何匹配的参数，您可能还想发送一个默认的响应  
  return; // 明确表示函数结束  
}