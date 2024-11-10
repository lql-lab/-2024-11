# include <iostream>
using namespace std;

void swap(int &x,int &y)
{
    // 将引用作为参数，拓宽了外层函数的变量的作用域。
    int temp = x;
    x = y;
    y = temp;
}
int& st(void)
{
    static int a = 10;
    a++;
    cout << "st " << a << endl;
    int &b = a;
    return b;
}
// 引用也可以使用const修饰，防止误更改。
void print(const int &a)
{
    cout << a << endl;
}
int main()
{
    int a = 0,c = 0;
    // 引用变量必须初始化，且无法更改指向。
    int &b  = a;
    // 引用变量与它的引用共用一个地址，指向同一块空间。
    // 实际上，引用是一个指针常量，但编译器会帮助完善使用引用时的指针相关操作，所以可以当作非指针变量使用。
    b = 20;
    cout << "sizeof(b) = " << sizeof(b) << endl;
    cout << "sizeof(int * const) = " << sizeof(int * const) << endl;
    cout << "&b = " << &b << endl;
    cout << "&a = " << &a << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(b,c);
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    st();
    // 引用拓宽了静态局部变量的作用域，可以在其原来的作用域之外访问它。
    st() = 0;
    st();
    const int &f = 10;
    // const修饰可以让引用指向一个常量，实际操作为：
        // int temp = 10;
        // const int &f = temp;
    return 0;
}