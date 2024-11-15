# include <iostream>

using namespace std;

int main()
{
    // 初始化。
    int score_num = 0;
    int max_score = 0, min_score = -1, temp_score = 0;
    double sum_score = 0.0;
    cin >> score_num;
    for (int i = 0 ; i < score_num ; ++i)
    {
        cin >> temp_score;
        // 记录最高分，最低分。
        if (temp_score > max_score)
        {
            max_score = temp_score;
        }
        // 最低分可以为0。
        if (min_score > temp_score || min_score == -1)
        {
            min_score = temp_score;
        }
        sum_score += temp_score;
    }
    // 去除最高分，最低分。
    sum_score -= (max_score + min_score);
    // 输出。
    printf("%.2f", (sum_score / (score_num - 2)));
    printf("\n");
    return 0;
}