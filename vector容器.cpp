# include <iostream>
using namespace std;
# include <vector>
# include <algorithm>

class Person
{
public:
    int num;
    vector<int> list;
    Person(int num)
    {
        this->num = num; 
    }
};
void print(int num)
{
    cout << num << endl;
}
int main()
{
    // vector容器是一个兼容各种数据类型的模板，可以执行数组的功能。
    vector<Person> person;
    // vector的构造函数。
    vector<int> arr(10, 0);
    vector<int> arr1(arr.begin(), arr.end());
    vector<int> arr2(arr);
    // vector赋值操作。
    arr1 = arr; // 可以使用等号。
    arr1.assign(5,250); // 也可以使用assign函数，与构造函数使用方法相同。
    Person person1(4);
    Person person2(3);
    Person person3(1);
    vector<int> v1;
    // 尾部插入。
    v1.push_back(3);
    v1.push_back(2);
    vector<int> v2;
    v2.push_back(5);
    v2.push_back(9);
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(7);
    person1.list = v1;
    person2.list = v2;
    person3.list = v3;
    person.push_back(person1);
    person.push_back(person2);
    person.push_back(person3);
    // 迭代器，提供访问所有容器中元素的便捷方法。
    for (vector<Person>::iterator it = person.begin() ; it != person.end() ; it++)
    {
        cout << it->num << endl;
        cout << "here is for_each" << endl;
        // 遍历算法for_each，可以对每个迭代器所指元素实现自定义的操作。
        for_each(it->list.begin(), it->list.end(), print);
        cout << "out of for_each" << endl;
    }
    // vector的属性。
    cout << "capacity = " << arr.capacity() << endl; // 容量
    cout << "size = " << arr.size() << endl; // 当前元素数量
    cout << "is empty = " << arr.empty() << endl; // 是否为空
    // vector的resize。
    arr.resize(20,0); // 如果大于原长度，后面补上指定的数。
    arr.resize(0); // 小于，则删除这些数据。
    // vector的插入删除，需要提供迭代器。
    arr.insert(arr.begin() + 1, 100);
    arr.erase(arr.begin() + 2);
    arr.erase(arr.begin() + 4, arr.begin() + 5);
    arr.clear();
    return 0;
}