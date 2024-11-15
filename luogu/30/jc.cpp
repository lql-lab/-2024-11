# include <iostream>
# include <algorithm>
# include <vector>
# include <string>

using namespace std;

string x_plus(string& num1, string& num2);
string m_plus(string& num1, string& num2);

// 计算阶乘，但是需要高精度。
int main()
{
    int n = 0;
    string t = "1";
    string m = "1";
    string sum = "0";
    cin >> n;
    // 计算部分。
    while( n > 0 )
    {
        int j = 1;
        for( string i = "1" ; j <= n ; i = x_plus(i, m), j++)
        {
            t = m_plus(t, i);
        }
        sum = x_plus(t, sum);
        t = "1";
        --n;
    }
    reverse(sum.begin(), sum.end());
    cout << sum << endl;
    return 0;
}

string m_plus(string& num1, string& num2)
{
    int len1 = num1.length();
    int len2 = num2.length();
    vector<int> result(len1 + len2, 0);
    for (int i = 0; i < len1 ; i++)
    {
        int carry = 0;
        for (int j = 0; j < len2 ; j++)
        {
            result[i + j] += carry + (num1[i] - '0') * (num2[j] - '0');
            carry = result[i + j] / 10;
            result[i + j] %= 10;
        }
        if (carry > 0)
        {
            result[i + len2] += carry;
        }
    }
    while (result.size() > 1 && result.back() == 0)
    {
        result.pop_back();
    }
    string res;
    for (int num : result)
    {
        res += '0' + num;
    }
    return res;
}

string x_plus(string& num1, string& num2)
{
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
    int carry = 0;
    for (int i = 0; i < min ; i++)
    {
        result[i] = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = result[i] / 10;
        result[i] = result[i] % 10;
    }
    for (int i = min; i < max + 1 ; i++)
    {
        if (i < max)
        {
            result[i] = (long_num[i] - '0') + carry;
            carry = result[i] / 10;
            result[i] = result[i] % 10;
        }
        else
        {
            result[i] = carry;
        }
    }
    while (result.size() > 1 && result.back() == 0)
    {
        result.pop_back();
    }
    string res;
    for (int num : result)
    {
        res += ('0' + num);
    }
    return res;
}
