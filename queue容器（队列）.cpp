# include <iostream>

# include <queue>

using namespace std;

int main()
{
    // 相比于栈，可以查看队首的值。
    queue<int> my_queue;
    if (my_queue.empty())
    {
        my_queue.push(1);
        my_queue.push(2);
        my_queue.push(3);
        my_queue.push(4);
        my_queue.push(5);
    }
    cout << my_queue.front() << "\t" << my_queue.back() << endl;
    cout << my_queue.size() << endl;
    queue<int> my_queue2 = my_queue;
    my_queue2.pop();
    my_queue2.swap(my_queue);
    return 0;
}