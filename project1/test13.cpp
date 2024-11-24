#include <iostream>
#include <string>
using namespace std;

class Employee 
{
private:
    string name;
    string street;
    string city;
    int zip;
public:
    Employee(string n, string s, string c, int z) : name(n), street(s), city(c), zip(z) {}
    void change_name(string newName) 
    {
        name = newName;
    }
    void display() 
    {
        cout << "Name: " << name << "\n";
        cout << "Street: " << street << "\n";
        cout << "City: " << city << "\n";
        cout << "Zip: " << zip << "\n";
    }
};

int main() {
    Employee e1("aaa", " St", "town", 1);
    Employee e2("ccc", " St", "town", 2);
    Employee e3("ddd", " St", "town", 3);
    Employee e4("eee", " St", "town", 4);
    Employee e5("fff", " St", "town", 5);
    e1.display();
    e1.change_name("bbb");
    e1.display();
    Employee* employees[5]={&e1,&e2,&e3,&e4,&e5};
    Employee employees2[5]={e1,e2,e3,e4,e5};
    return 0;
}
