#include<vector>
#include<iostream>

using namespace std;

class a;

vector<a> bec;

class a
{
public:
    int x;
    a(int x_):x(x_){}
    void add(a& p)
    {
        bec.push_back(p);
    }
};

int main()
{
    a bb(1);
    bb.add(bb);
    for(a kv:bec)
    {
        std::cout<<kv.x<<"\n";
    }
    return 0;
}