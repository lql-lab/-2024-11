# include <iostream>
using namespace std;

int main()
{
    // 运算 +,-,*,/,类比c.
    // 但 <,> , ==运算优先级弱于输出endl.
    int x = 1,y = 2;
    cout << "x == y" << (x == y) << endl;
    cout << "int / int = int like this x(1)/y(2) = " << x/y << endl;
    // 保留了++,--运算.
    cout << "++" << x++ << endl;
    cout << "x + y = " <<x + y << endl;
    // 对于逻辑运算,其优先级低,也要加上括号,三目运算同理.
    cout << "bool calcultion " << (x == y || y > x) << endl; 
    // 三目运算会返回一个*(point)可以作为右值,也可以作为左值.
    cout << "? : -->" << ((x < y ? x : y) = 3 ) << endl;
    // 赋值运算与c相同,结果为写进的值.
    cout << "x = " << (x = x) << endl;
    cout << "y = " << (y = y) << endl; 
    cout << "the x(2) + y(3),y = y --> " << (x + y , y = y) << endl;
    system("read");
    return 0;
}