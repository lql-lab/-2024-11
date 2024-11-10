# include <iostream>
using namespace std;
# include"circle.hpp"
# include"point.hpp"

int main()
{
    Circle circle;
    Point point;
    circle.set_point(10,10);
    circle.set_midr(10);
    cout << circle.get_r() << endl;
    cout << *(circle.get_xy()) << "\t" << *(circle.get_xy() + 1) << endl;
    point.set_point(10,20);
    cout << *(point.get_point()) << "\t" << *(point.get_point() + 1) << endl;
    cout << point.p_circle(circle) << endl;
    return 0;
}