# include <iostream>
using namespace std;

class animal
{
public:
    int a;
};
// 类的继承类型同样有三种权限，对继承而来的部分加以保护。
// 区别在于即使是公共权限，也无法将父类中被保护的成员开放。
// 继承时会将所有成员都交给子类，即使它们没有权限访问。
class sheep :virtual public animal
{
public:
    int b;
};
// 虚继承，以指针的方式传递数据，而非直接传递。可以防止多次传递继承于同一个基类的成员。
// 系统会构造一个虚继承，虚函数表，储存这些指针所代表的继承关系。
class tuo :virtual public animal
{
public:
    static int m;
    int b;
};
int tuo::m = 10;
class cnm :public sheep, public tuo
{
public:
    static int m;
    int b;
};
int cnm::m = 20;
int main()
{
    cnm sheeptuo;
    sheeptuo.sheep::b = 10;
    // 当有同名成员存在时，无特殊声明情况下，子类优先调用自己的成员。
    cout << sheeptuo.m << endl;
    cout << sheeptuo.tuo::m << endl;
    cout << cnm::tuo::m << endl;
    return 0;
}