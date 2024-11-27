#include <iostream>
#include <string>
#include <cctype>
bool isSafePassword(const std::string& password) 
{
    // 1. 长度在8~16之间
    if (password.length() < 8 || password.length() > 16) 
        return false;
    // 2. 开头必须是大写字母
    if (!isupper(password[0])) 
        return false;

    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    // 3. 检查其他条件
    for (char ch : password) 
    {
        // 判断是否有小写字母
        if (islower(ch)) 
            hasLower = true;
        // 判断是否有数字
        if (isdigit(ch)) 
            hasDigit = true;
        // 判断是否有特殊字符
        if (ch == '-' || ch == '!' || ch == '@' || ch == '#' || ch == 'S' || ch == '%' || ch == '*') 
            hasSpecial = true;
    }
    // 确保包含至少一个小写字母，一个数字和一个特殊符号
    return hasLower && hasDigit && hasSpecial;
}
int main() 
{
    std::string password;
    std::cout << "请输入密码: ";
    std::cin >> password;
    // 调用函数来检查密码安全性
    if (isSafePassword(password))
        std::cout << "true" << std::endl; 
    else 
        std::cout << "false" << std::endl;
    return 0;
}
