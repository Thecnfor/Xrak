<?php    
  
// ESP8266的IP地址和端口    
$esp8266_ip = '192.168.1.177'; // 替换为你的ESP8266的IP地址    
$port = 80; // ESP8266上Web服务器的端口    
  
// 检查是否通过GET请求传递了action参数  
if (isset($_GET['action'])) {    
    $command_to_send = $_GET['action'];    
    $url = "http://{$esp8266_ip}:{$port}/command?action={$command_to_send}";    
  
    // 初始化curl    
    $ch = curl_init($url);    
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);    
    $response = curl_exec($ch);    
      
    // 检查curl是否出现错误  
    if(curl_errno($ch)){    
        $error_msg = curl_error($ch);    
        echo "cURL Error: " . $error_msg;    
    } else {  
        // 如果没有错误，则输出响应  
        echo "Response: " . $response;    
    }  
    curl_close($ch);    
} else {  
    // 如果没有传递action参数，可以输出一个错误消息或默认响应  
    echo "No action specified.";  
}  
?>