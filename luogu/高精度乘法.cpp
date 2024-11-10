# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

string x_plus(string& num1, string& num2);
int main()
{
    string num1;
    string num2;
    getline(cin, num1);
    getline(cin, num2);
    string result = x_plus(num1, num2);
    cout << result << endl;
    return 0;
}
string x_plus(string& num1, string& num2)
{
    int len1 = num1.length();
    int len2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
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
    reverse(res.begin(), res.end());
    return res;
}