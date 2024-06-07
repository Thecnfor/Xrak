
 #include <ESP8266WiFi.h>  
#include <ESP8266WebServer.h>  
  
const char* ssid = "HUAWEI-W"; // 替换为您的WiFi SSID  
const char* password = "W@18025693031"; // 替换为您的WiFi密码  
  
ESP8266WebServer server(8080);  
  
void handleRoot() {  
  String message;  
  if (server.hasArg("data")) {  
    message = "Received data: " + server.arg("data");  
  } else {  
    message = "No data received";  
  }  
  server.send(200, "text/plain", message);  
  Serial.println(message);
}  
  
void setup(void) {  
  Serial.begin(115200);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);  
    Serial.print(".");  
  }  
  Serial.println("");  
  Serial.print("Connected to ");  
  Serial.println(ssid);  
  Serial.print("IP Address: ");  
  Serial.println(WiFi.localIP());  
  
  server.on("/", handleRoot);  
  server.begin();  
  Serial.println("HTTP server started");  
}  
  
void loop(void) {  
  server.handleClient();  
}