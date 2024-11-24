#if 0
#include <iostream>
using namespace std;
class Sample
{
public:
	void disp(const char *txt, char *cap)
	{
		cout<<"Txt: "<<txt;
		cout<<"Cap: "<<cap<<endl;
	}
	void disp(const char *txt, unsigned int type)
	{
		cout<<"Txt: "<<txt;
		cout<<"Type: "<<type<<endl;
	}
};
int main()
{
	Sample my;
	my.disp("Good!", (unsigned int)0);
    return 0;
}
#endif
#include <iostream>
using namespace std;
class Sample
{
public:
	int Max(int x, int y)
	{
		return x > y ? x : y;
	}
	int Max(int x, int y, int z = 0)
	{
		if(x > y)
			return x > z ? x : z;
		else
			return y > z ? y : z;
	}
};
void main()
{
	Sample a;
    a.Max(1,2,0);
}