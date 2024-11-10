# include <iostream>
using namespace std;
# include <string>

class MAN
{
public:
    string name;
// 保护权限的成员可以被子类访问，但私有权限的成员只能在这一个类内部访问。
protected:
    string car;
private:
// 类的成员属性一般设置为私有，外界只能通过类中设置的公共方法访问，
// 于是可以借此设置对外的读写权限，也可以控制写入的数据的范围。
    string num;
public:
// 在类的内部，可以访问所有成员。
    void print()
    {
        cout << name << "\t" << car << "\t" << num << endl;
    }
private:
    void change(string new_name)
    {
        name = new_name;
    }
};

int main()
{
    MAN man;
    man.name = "my_name";
    man.print();
    // 类的私有，保护成员无法在类外访问。
        // man.change("aaa");
        // cout << man.car;
    return 0;
}