# include <iostream>
# include <string>

using namespace std;

struct STU
{
    string name;
    int score1;
    int score2;
    int score3;
};

int main()
{
    // 初始化。
    int num = 0;
    cin >> num;
    STU students[num];
    // 输入第一个。
    cin >> students[0].name >> students[0].score1 >> students[0].score2 >> students[0].score3;
    // 临时最大值。
    STU p_students = students[0];
    // 输入其余。
    for (int i = 1; i < num ; ++i)
    {
        cin >> students[i].name >> students[i].score1 >> students[i].score2 >> students[i].score3;
        // 判断是否更大。
        if ((p_students.score1 + p_students.score2 + p_students.score3 < students[i].score1 + students[i].score2 + students[i].score3))
            p_students = students[i];
    }
    // 输出。
    printf("%s %d %d %d\n", p_students.name.c_str(), p_students.score1, p_students.score2, p_students.score3);
    return 0;
}