# include <iostream>

# include <stack>

using namespace std;

int main()
{
    // stack栈结构。
    // 注意栈不含有遍历功能。
    // 含有的功能如下：
    stack<int> my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    my_stack.push(4);
    my_stack.push(5);
    cout << my_stack.top() << endl;
    if (! my_stack.empty())
    {
        stack<int> my_stack2(my_stack);
        stack<int> my_stack2 = my_stack;
        my_stack2.pop();
        my_stack2.swap(my_stack);
    }
    cout << my_stack.size() << endl;
    return 0;
}