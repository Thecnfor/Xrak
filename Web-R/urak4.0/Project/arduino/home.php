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
    if (curl_errno($ch)) {  
        $error_msg = curl_error($ch);  
        echo "cURL 出错: " . $error_msg;  
    } else {  
        // 如果没有错误，则输出响应  
        echo "成功发送命令: {$command_to_send}，ESP8266响应: " . $response;  
    }  
    curl_close($ch);  
}
    // 如果没有传递action参数，检查是否为POST请求  
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {  
        $data = json_decode(file_get_contents('php://input'), true);  
        if (!empty($data) && isset($data['x']) && isset($data['y'])) {  
            $x = $data['x'];  
            $y = $data['y'];  
      
            // 在这里处理你的X和Y值...  
            $url = "http://{$esp8266_ip}:{$port}/command?x={$x}&y={$y}";  
      
            // 初始化curl...  
            $ch = curl_init($url);  
            curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);  
            $response = curl_exec($ch);  
      
            if (curl_errno($ch)) {  
                $error_msg = curl_error($ch);  
                $output = json_encode(['status' => 'error', 'message' => "cURL 出错: " . $error_msg]);  
            } else {  
                $output = json_encode(['status' => 'success', 'message' => "成功发送命令X: {$x}，Y: {$y}，ESP8266响应: " . $response]);  
            }  
            curl_close($ch);  
      
            // 返回 JSON 响应给客户端  
            echo $output;  
        } else {  
            echo json_encode(['status' => 'error', 'message' => 'JSON 数据格式错误.']);  
        }  
    } else {  
        echo json_encode(['status' => 'error', 'message' => '非法请求']);  
    }  
?>