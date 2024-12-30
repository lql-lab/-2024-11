# include <iostream>
using namespace std;

void func()
{
    cout << "func" << endl;
}
// 在同一个作用域内，使用参数不同的同名函数可以同时存在。
void func(int a ,int b = 10)
{
    cout << "func int" << endl;
}
void func(int a)
{
    cout << "func int" << endl;
}
void func1(int &a)
{
    cout << "func1 int &" << endl;
}
void func1(const int &a)
{
    cout << "func1 const int &" << endl;
}

int main ()
{
    // 按照传入参数的形式顺序(不同类别的参数之间的顺序)等等，判断调用那个版本的函数。
    func();
    // 注意避免由于默认参数导致的二义性，如：
        // func(10);
    func(10,10);
    int a = 0;
    // 遇到引用既可以传给常量引用和普通引用时，优先进入使用普通引用参数的函数中。
    func1(a);
    func1(10);
    return 0;
}