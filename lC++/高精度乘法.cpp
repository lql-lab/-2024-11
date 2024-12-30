#include <iostream>
#include <string>
# include <algorithm>
#include <vector>

// 函数用于将两个大整数相乘
std::string multiply(std::string& num1, std::string& num2) {
    // 获取两个数的长度
    int m = num1.length();
    int n = num2.length();
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    // 创建结果数组，长度为m + n
    std::vector<int> result(m + n, 0);

    // 模拟竖式乘法
    for (int i = 0; i < m; ++i) {
        int carry = 0;
        for (int j = 0; j < n; ++j) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + result[i + j] + carry;
            result[i + j] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            result[i + n] += carry;
        }
    }

    // 去除前导0
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());

    // 将结果数组转换为字符串
    std::string res;
    for (int num : result) {
        res += (num + '0');
    }

    return res;
}

int main() {
    // std::string num1 = "12345678901234567890";
    // std::string num2 = "98765432109876543210";
    std::string num1;
    std::string num2;
    std::cin >> num1;
    std::cin >> num2;

    std::string product = multiply(num1, num2);

    std::cout << product << std::endl;

    return 0;
}
