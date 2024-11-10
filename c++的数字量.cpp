# include <iostream>
# define DAY 7
using namespace std;

int main () 
{
    // 有效长度 e10
    int a = 10;
    const int b = 5;
    cout << "a = " <<  a << " can't change the value of 'b' = " << b << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "int = " << sizeof(int) << " short = " << sizeof(short) << " long = " << sizeof(long) << \
    " long long = " << sizeof(long long) << "float = " << sizeof(float) << "double" << sizeof(double) << endl;
    cout << "int * = " << sizeof(int *) << endl;
    // 有效长度 e7
    float flo = 3.14f;
    // 有效长度 e11
    double dbl = 3.1415926;
    double with_e = 1.0e-6;
    cout << "double = " << dbl << endl;
    // 默认输出 e6.
    return 0;
}
