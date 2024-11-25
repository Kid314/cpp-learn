#include<iostream>
#include<string>
#include<cctype>
std::string str1;
void solve()
{
    std::string result;
    for (char ch : str1)//注意！！！无法在str1上面直接修改！！！ 
    {
        //用islower函数判断是否是小写
        if (std::islower(ch)) 
            result += std::toupper(ch);
        //用isupper来判断是否大写
        else if (std::isupper(ch)) 
            result += std::tolower(ch);
        else 
            result += ch;
    }
    std::cout<<result;
}
int main()
{
    std::cin>>str1;
    solve();
    return 0;
}