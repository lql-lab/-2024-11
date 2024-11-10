# include <iostream>
using namespace std;
# include <string>

int main ()
{
    char the_ch = 'a';
    cout << the_ch << endl;
    cout << "char = " << sizeof(char) << endl;
    int from_char = (int)the_ch;
    cout << "the ascii of 'a' = " <<from_char << endl;
    // 注意用双引号定义字符串.
    char chars_1[10] = "chars" ;
    char chars_2[] = "chars_2";
    // 必须包含头文件<string>.
    string a_string = "'string'";
    cout << "this is a string: " << a_string << endl;
    return 0;
}