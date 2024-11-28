# include <iostream>
using namespace std;
# include <string>

class User
{
private:
    string name;
    int sex;
public:
    void set(int a)
    {
        sex = a;
    }
// 在创建一个对象时，就会自动调用构造函数。
    // 默认构造。
User()
{

}
    // 含参构造。
User(int a = 1)
{
    name = "aaa";
    set(a);
}
    // 列表初始化。
User(string a, int b) :name(a), sex(b)
{

}
    // 析构函数。
~User()
{
    name = "";
    sex = -1;
}
    // 拷贝构造。
    // 下列为一个浅拷贝。
User(const User &user)
{
    name = user.name;
    sex = user.sex;
}
};

int main()
{
    User user(0);
    return 0;
}