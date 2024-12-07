#include<vector>
#include<iostream>

class a
{
public:
    int aa;
    a(int aa_):aa(aa_){}
};

std::vector<a> vec;

void add()
{
    a aa(1);
    vec.push_back(aa);
}

int main()
{
    add();
    std::cout<<vec[0].aa;

    return 0;
}
