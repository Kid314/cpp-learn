#include<bits/stdc++.h>

int main()
{
    std::string str1="helloworld";
    std::string str2="kkkdddd";
    if(rename(str1.c_str(),str2.c_str())!=0)
    {
        throw std::logic_error("rename log file failed");
    }
    std::cout<<str1;
    return 0;
}