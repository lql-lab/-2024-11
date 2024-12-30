# include <iostream>
using namespace std;

class User
{
private:
    string name;
    int sex;
public:
    mutable int num = 0;
    void set(int sex)
    {
        // this指针可以用于区分变量。
        this->sex = sex;
    }
    int show(void)
    {
        return sex;
    }
    User& more(void)
    {
        // 防止访问非法地址。
        if (this != NULL)
        {
            cout << this << endl;
            this->sex += 1;
            // this指针是实例调用方法时传递的指向自身地址的指针常量，默认不会显示。
            // 使用this指针可以方便的实现链式编程。  
        }
        return *this;
    }
    // 常函数：接受的this指针经const修饰。自身无法修改其所指的空间。
    void print_num() const
    {
        num++;
        cout << this << endl;
        cout << num << endl;
    }
User(int a = 1)
{
    name = "aaa";
    set(a);
}
User(string a, int b):name(a),sex(b)
{

}
~User()
{
    name = "";
    sex = -1;
}
User(const User &user)
{
    name = user.name;
    sex = user.sex;
}
};
int main()
{
    User user;
    // 常量对象，this指针类型为常量指针常量，故只能调用常函数。
    const User user1;
    user1.print_num();
    user.more().more().more();
    cout << user.show() << endl;
    return 0;
}