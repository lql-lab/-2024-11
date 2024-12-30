# include <iostream>
# include <string>
using namespace std;

int main()
{
    int a_int = 0;float a_float = 0.0f;double a_double = 0.0;string a_str = "";bool a_bool = true;
    // 只能得到整数和浮点数的整数部分,得到字符则无法写入内存.
    cin >> a_int;
    cout << "a_int = " << a_int << endl;
    cin >> a_float;
    cout << "need a str" << endl;
    cin >> a_str;
    // 只会读取并写入第一个空格,换行符前的内容.
    cout << "a str = " << a_str << endl;
    cout << "to_bool " << endl;
    cin >> a_bool;
    // 可以接收数字,非零为真.
    cout << "the value of bool is = " << a_bool << endl;
    // system("read");
    return 0;
}