# include <iostream>

// 结构体储存学生信息。
struct STUDENT
{
    int index;
    int normsl_score;
    int extra_score;
};

using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    STUDENT students[num];
    for (int i = 0 ; i < num ; ++i)
    {
        // 输入。
        cin >> students[i].index >> students[i].normsl_score >> students[i].extra_score;
        // 同时判断是否优秀，并输出。
        if ((students[i].normsl_score + students[i].extra_score > 140 && students[i].normsl_score * 7 + students[i].extra_score * 3 >= 800))
        {
            cout << "Excellent" << endl;
        }
        else
        {
            cout << "Not excellent" << endl;
        }
    }
    return 0;
}