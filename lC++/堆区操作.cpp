# include <iostream>
using namespace std;

int* new_int(int value)
{
    int *p = new int(value);
    return p;
}
int* new_arr(int len)
{
    int *p = new int[len];
    return p;
}
int main()
{
    int *p = new_int(10);
    cout << "值为：" << *p << endl;
    delete p;
    // 释放空间后，重新变为空闲空间，原来存的值丢失，但还可以访问这块空间。
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    int *q = new_arr(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << q[i] << endl;
    }
    delete q;
    for (int i = 0; i < 5; i++)
    {
        cout << q[i] << endl;
    }
    return 0;
}