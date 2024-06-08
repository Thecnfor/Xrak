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
      Serial.print("TURN_ON");
      Serial.println("_control");
    } else if (action.equals("turnOff")) {  
      Serial.print("turnOff");
      Serial.println("_control");
    }   
    server.send(200, "text/plain", "读取成功 " + action);  //读取成功
  }
  if (server.hasArg("x")) {
    String x = server.arg("x");
    String y = server.arg("y");
    Serial.print(x+","+y+"/ln");
    server.send(200, "text/plain", "读取成功");  //读取成功
  }
}  