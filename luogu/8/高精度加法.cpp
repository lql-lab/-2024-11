# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

using namespace std;

string x_plus(string& num1, string& num2);

int main()
{
    // 初始化。
    string num1;
    string num2;
    getline(cin, num1);
    getline(cin, num2);
    // 使用高精度加法。
    string result = x_plus(num1, num2);
    // 输出。
    cout << result << endl;
    return 0;
}

string x_plus(string& num1, string& num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len1 = num1.length();
    int len2 = num2.length();
    int max = len1 > len2 ? len1 : len2;
    int min = len1 > len2 ? len2 : len1;
    string long_num = num1;
    if (max == len2)
    {
        long_num = num2;
    }
    vector<int> result(max + 1, 0);
    // 进位的数字。
    int carry = 0;
    // 处理共有位数。
    for (int i = 0; i < min ; i++)
    {
        result[i] = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = result[i] / 10;
        result[i] = result[i] % 10;
    }
    // 处理较大数的高位。
    for (int i = min; i < max + 1 ; i++)
    {
        if (i < max)
        {
            // 这里继承了低位的进位数字。
            result[i] = (long_num[i] - '0') + carry;
            carry = result[i] / 10;
            result[i] = result[i] % 10;
        }
        // 处理可能最高位的进位。
        else
        {
            result[i] = carry;
        }
    }
    // 除去前导零。
    while (result.size() > 1 && result.back() == 0)
    {
        result.pop_back();
    }
    // 字符串储存结果。
    string res;
    for (int num : result)
    {
        res += ('0' + num);
    }
    reverse(res.begin(), res.end());
    return res;
}

