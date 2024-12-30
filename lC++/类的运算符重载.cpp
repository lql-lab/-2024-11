# include <iostream>
using namespace std;

class MYint
{
public:
    int *p;
public:
    MYint()
    {
        cout << "111" << endl;
        p = new int(0);
    }
    MYint(int value)
    {
        cout << "222" << endl;
        p = new int(value);
    }
    MYint(const MYint& myint)
    {
        cout << "333" << endl;
        p = new int(*(myint.p));
    }
    ~MYint()
    {
        cout << "444" << endl;
        if (p != NULL)
        {
            delete p;
            p = NULL;
        }
    }
    void operator()(void);
    MYint& operator++();
    MYint* operator&();
    MYint operator++(int);
};
// 运算符重载，可以通过全局函数重载，也可以通过成员函数重载。
MYint operator+(MYint& int1, MYint& int2)
{
    MYint temp(*int1.p + *int2.p);
    return temp;
}
MYint* MYint::operator&()
{
    return this;
}
ostream& operator<<(ostream& cout, MYint &myint)
{
    cout << *(myint.p);
    return cout;
}
MYint& MYint::operator++()
{
    (*p)++;
    return *this;
}
MYint MYint::operator++(int)
{
    MYint temp = *this;
    (*p)++;
    return temp;
}
// 仿函数。
void MYint::operator()(void)
{
    cout << *this << endl;
}
int main()
{
    MYint int1(2), int2(3);
    cout << &int1 << endl;
    cout << &int1 << endl;
    cout << int1 << int2 << endl;
    MYint int3 = int1 + int2;
    cout << int3 << endl;
    int3();
    cout << ++(int1++) << endl;
    return 0;
}