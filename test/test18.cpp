#include <iostream>
using namespace std;

int main() 
{
    int a, b;
    cout << "请输入两个整数：" << endl;
    cin >> a >> b;

    try {
        if (b == 0) {
            throw b;
        }
        cout << "两数相除的结果为：" << a / b << endl;
    } catch (const int e) {
        cout << "发生错误：\n" << e << endl;
    }

    return 0;
}