#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ESP8266WebServer.h>  
  
ESP8266WebServer server(80);  
  
const char* ssid = "HUAWEI-W";  
const char* password = "W@18025693031";  
  
void handleRoot() {  
  server.send(200, "text/plain", "Arduino is ready");  
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
  if (server.hasArg("action")) {  //检查请求中是否包含 action 参数
    String action = server.arg("action");  //获取action值
    if (action.equals("turnOn")) {  //action.equals("turnOn")就是action==“turnOn”
      Serial.print("TURN_ON\n");
    } else if (action.equals("turnOff")) {  
      Serial.print("turnOff\n");
    }   
    server.send(200, "text/plain", "Command received: " + action);  //读取成功
  } else {  
    server.send(400, "text/plain", "Invalid request");  //读取非action返回
  }  
}  