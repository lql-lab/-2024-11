# include <iostream>
using namespace std;
# include <string>

class Phone
{
public:
    string name;
public:
    Phone()
    {

    }
    Phone(string n)
    {
        name = n;
    }
    ~Phone()
    {
        name = "";
    }
    Phone(const Phone &phone)
    {
        name = phone.name;
    }
};
class Person
{
    public:
        string name;
        Phone phone;
    Person()
    {
        name = "aaa";
        // phone = Phone("aaa");
        phone.name = "bbb";
    }
    ~Person()
    {

    }
    Person(const Person &p)
    {
        name = p.name;
        phone = p.phone;
    }
};

int main()
{
    // 当一个类中含有另一个类，或者和其他类有继承关系，会先构造这些部分，再构造自己。
    // 注意，外层的类无法访问内部类的保护成员。
    // 析构时相反。
    Person person;
    cout << person.name << "\t" << person.phone.name << endl;
    return 0;
}