# include <iostream>
using namespace std;

class BOX
{
private:
    int b_h;
    int b_w;
    int b_l;
public:
    int set_H(int h)
    {
        if (h > 0)
        {
            b_h = h;
        }
        return h;
    }
    int get_H(void)
    {
        return b_h;
    }
    int set_W(int w)
    {
        if (w > 0)
        {
            b_w = w;
        }
        return w;
    }
    int get_W(void)
    {
        return b_w;
    }
    int set_L(int l)
    {
        if (l > 0)
        {
            b_l = l;
        }
        return l;
    }
    int get_L(void)
    {
        return b_l;
    }
    int pren(void)
    {
        return 2 * (b_l * b_h + b_l * b_w + b_w * b_h);
    }
    int area(void)
    {
        return b_h * b_l * b_w;
    }
    bool is_same(BOX &box)
    {
        bool ret = false;
        if (area() == box.area() && pren() == box.pren())
        {
            ret = true;
        }
        return ret;
    }
};
bool box_same(BOX &box1, BOX &box2)
{
    bool ret = false;
    if(box1.pren() == box2.pren() && box1.area() == box2.area())
    {
        ret = true;
    }
    return ret;
}

int main()
{
    BOX box1,box2;
    box1.set_H(10);
    box1.set_L(10);
    box1.set_W(10);
    // 和结构体一样，相同类的对象之间也可以直接赋值。改变属性的值。
    // 这是因为编译器会默认提供一个拷贝函数，使我们能进行显示构造。
    box2 = box1;
    cout << box1.pren() << endl;
    cout << box_same(box1, box2) << endl;
    cout << box1.is_same(box2) << endl;
    return 0;
}