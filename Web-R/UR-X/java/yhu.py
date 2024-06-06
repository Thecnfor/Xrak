# 假设这是编码后的密码字符串  
encoded_password = "54&72&104&73&81&33&80&57&"  
  
# 初始化一个空字符串来保存解码后的密码  
decoded_password = ''  
  
# 遍历编码后的字符串，跳过'&'字符并处理每对十六进制数字  
hex_pairs = encoded_password.split('&')  # 使用'&'作为分隔符分割字符串  
for hex_pair in hex_pairs:  
    # 跳过空字符串（例如，如果字符串以'&'结尾）  
    if not hex_pair:  
        continue  
      
    # 将十六进制对转换为整数，并检查其是否为有效的十六进制字符串  
    try:  
        decoded_byte = int(hex_pair, 16)  
        decoded_char = chr(decoded_byte)  
        decoded_password += decoded_char  
    except ValueError:  
        # 如果不是有效的十六进制字符串，则忽略它（通常这里不应该发生，因为我们已经分割了字符串）  
        print(f"Invalid hex pair: '{hex_pair}'")  
  
# 输出解码后的密码  
print("解码后的密码:", decoded_password)