#include <ESP8266WiFi.h>  
  
// 替换为你的WiFi网络SSID和密码  
const char* ssid = "RedG";  
const char* password = "12345678";  

WiFiServer server(8266);//你要的端口号，随意修改，范围0-65535

void setup() {  
  Serial.begin(115200); // 启动串口通信，设置波特率为115200  
  delay(10);  
  
  // 连接到WiFi网络  
  WiFi.begin(ssid, password);  
  Serial.println("");  
  
  // 等待WiFi连接  
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);  
    Serial.print(".");  
  }  

  server.begin();
    server.setNoDelay(true);  //加上后才正常些

  
  // 连接成功后打印网络信息  
  Serial.println("");  
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");  
  Serial.println(WiFi.localIP()); // 打印Arduino设备的IP地址  
}  
  
void loop() {  
  // 这里可以写你的主程序代码，例如通过WiFi发送或接收数据等。  
}