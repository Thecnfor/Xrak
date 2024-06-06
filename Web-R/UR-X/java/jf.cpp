#include <iostream>  
#include <string>  
#include <sstream>  
#include <vector>  
  
std::string decodeHexPassword(const std::string& encodedPassword) {  
    std::istringstream iss(encodedPassword);  
    std::string hexPair;  
    std::vector<unsigned char> decodedBytes;  
    char delimiter = '&';  
  
    // 跳过前缀  
    std::getline(iss, hexPair, '"');  
    std::getline(iss, hexPair, '"');  
  
    // 循环读取每对十六进制数  
    while (std::getline(iss, hexPair, delimiter)) {  
        // 跳过空的hexPair（如果字符串以&结尾）  
        if (hexPair.empty()) continue;  
  
        // 将每对十六进制数转换为无符号字符  
        unsigned int byte;  
        std::stringstream ss;  
        ss << std::hex << hexPair;  
        ss >> byte;  
  
        // 将无符号字符添加到解码后的字节数组中  
        decodedBytes.push_back(static_cast<unsigned char>(byte));  
    }  
  
    // 将解码后的字节数组转换为字符串  
    std::string decodedPassword(decodedBytes.begin(), decodedBytes.end());  
    return decodedPassword;  
}  
  
int main() {  
    std::string encodedPassword = "baseinfoSet_TELECOMPASSWORD\":\"54&72&104&73&81&33&80&57&\"";  
      
    // 提取十六进制编码的密码部分  
    size_t startPos = encodedPassword.find_first_of(':') + 1;  
    size_t endPos = encodedPassword.find_last_of('"');  
    std::string hexEncodedPassword = encodedPassword.substr(startPos, endPos - startPos - 1);  
  
    // 解码密码  
    std::string decodedPassword = decodeHexPassword(hexEncodedPassword);  
  
    // 输出解码后的密码  
    std::cout << "解码后的密码: " << decodedPassword << std::endl;  
  
    return 0;  
}