# include <iostream>
# include <string>

using namespace std;

int main()
{
    // string的构造与赋值：
    string str1("hellow word!");
    string str2(10, '1');
    string str3(str2);
    // 可选赋值范围：
    str3.assign("aaaaaa", 5);
    str2.assign(10,'2');
    str1.assign(str1);
    str2 = str3 = str1;
    // 字符串拼接：
    str1 += "aaa";
    str2.append("aaaaaaa");
    // 可选拼接的范围：
    str3.append("66777", 2, 3);
    cout << str3 << endl;
    // 字符串查找，替换：
    int pos = str1.find("rd");
    cout << pos << endl;
    // 可选被覆盖的范围：
    str1.replace(0, 12, "hello world ");
    cout << str1 << endl;
    // 字符串的比较：
    int ret = 0;
    ret = str1.compare(str2);
    cout << ret << endl;
    // 除了[]还可以使用at方法获取string字符串成员：
    str1.at(12) = 'b';
    cout << str1 << endl;
    // 字符串的插入和删除：
    str1.insert(13,"abal"); // 将该位置替换为这个字符串。
    cout << str1 << endl;
    str1.erase(12, 4); // 从该位置开始，删除指定个数元素。
    cout << str1 << endl;
    // 子串截取：
    string str4 = str1.substr(0, 5);
    cout << str4 << endl;
    return 0;
}