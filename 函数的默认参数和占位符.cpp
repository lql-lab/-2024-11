# include <iostream>
using namespace std;

// c++中定义的函数可以有默认参数。
// 有默认参数的局部变量可以不接收外层函数值的初始化。
void add_10(int &a, int b = 10)
{
    cout << "a + 10 = " << a + b << endl;
}
// 占位符，在调用该函数时必须提供一个符合占位符类型的值，虽然该值在函数内部无法被使用。
void print__(int)
{
    cout << "**************" << endl;
}

int main()
{
    int x = 0;
    add_10(x);
    print__(10);
    return 0;
}