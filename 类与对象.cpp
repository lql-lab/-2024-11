# include <iostream>
using namespace std;
# define PI 3.14

// 封装圆类的代码块。
// 类是一种特殊的结构体，它们的区别在于默认的成员访问权限，struct为公共权限，而class为私有权限。
class CIRCLE
{
    // 友元，可以访问私有成员。可以是类，也可以是函数，如果是某个类下的函数，需要声明其作用域。
friend void all(CIRCLE& );
    // 公共权限访问。
public:
    // 类的共有特征（成员）：
        // 属性（成员属性，成员变量）。
            // 静态成员属性。所有实例共用。
                // 在编译时创建（同静态变量，全局变量，常量），需要在类外初始化。
    static int r;
    int mid_r = 0;
public:
        // 方法（成员函数，成员方法）。 
        // 类的方法与属性分开存储，方法只会储存一次。
    int pren(void)
    {
        return PI * mid_r * 2;
    }
    // 静态函数，只能访问静态成员变量。
    static void ten(void)
    {
        r = 10;
        cout << r << endl;
    } 
private:
    void sad(void);
};
// 类外可以定义其共有成员，如静态变量，方法。
int CIRCLE::r = 100;
void CIRCLE::sad(void)
{
    cout << "sad" << endl;
}
void all(CIRCLE &circle)
{
    circle.sad();
}

int main()
{
    // 实例化一个类的对象。
    // 空对象占据一个字节的内存，用于确定其地址。
    CIRCLE circle;
    // 对这个对象进行类的操作。
    circle.mid_r = 10;
    int pren = circle.pren();
    cout << pren << endl;
    // 可以使用类型名称()创建一个匿名对象，在这一行后立即销毁。
    cout << CIRCLE().r << endl;
    return 0;
}