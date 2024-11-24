#include<iostream>
#include<string>
#include<vector>

int main()
{
    std::vector<std::string> names;
    names.push_back("wgc");
    names.push_back("www");
#if 0
    for(int i=0;i<names.size();i++)
    {
        std::cout<<names[i]<<std::endl;
    }

#endif
    std::vector<std::string>::iterator iter=names.begin();

    while(iter!=names.end())
    {
        std::cout<<*iter<<std::endl;
        ++iter;
    }

    return 0;
}    