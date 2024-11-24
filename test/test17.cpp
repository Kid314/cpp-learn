#include <iostream>
#include<algorithm>
using namespace std;
class Student {
public:
    Student(int math = 0, int english = 0) : math_score(math), english_score(english) {}
    friend istream& operator>>(istream& in, Student& s) 
    {
        cout << "请输入数学成绩：";
        in >> s.math_score;
        cout << "请输入英语成绩：";
        in >> s.english_score;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Student& s) 
	{
        out << "数学成绩：" << s.math_score << "，英语成绩：" << s.english_score;
        return out;
    }
    bool operator>(const Student& s) const 
	{
        return max(math_score, english_score) > max(s.math_score, s.english_score);
    }
private:
    int math_score;
    int english_score;
};
int main()
{
	Student a(100,200);
	cout<<a<<"\n";
    Student b;
    cin>>b;
    cout<<(a>b)<<"\n";
	return 0;
}