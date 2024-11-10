# include <iostream>
using namespace std;
# include <string>

int main()
{
    // 可以使用cin的方法和一些全局函数来输入字符串。
    char arr[20] = {};
    // 注意使用get时要将当前位置的\n无效化后再进行下一次的输入。
    cin.get(arr, 20).get();
    char ch;
    // cin.get()还有一种char的重载，作为字符输入，会忽视“ ”和“\n”。
    cin.get(ch).get();
    string name;
    getline(cin, name);
    cout  << "arr == " << arr << endl;
    cout << "ch == " << ch << endl;
    cout << "name == " << name << endl;
    while (!cin.fail())// 等同于cin.get() == -1(EOF)。
    {
        cin >> ch;
        cout << ch;
    }
    return 0;
}