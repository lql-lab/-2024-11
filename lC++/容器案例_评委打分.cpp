# include <iostream>

# include <ctime>
# include <string>
# include <deque>
# include <vector>
# include <algorithm>

using namespace std;

class STUDENT
{
public:
    vector<int> scores;
    string name;
    double arge_score;

    STUDENT(string name)
    {
        this->name = name;
        scores.reserve(10);
    }
};

void creat(deque<STUDENT>& stu, int num);
void printall(deque<STUDENT>&);

int main()
{
    srand((unsigned int)(time(NULL)));
    deque<STUDENT> stus;
    creat(stus, 5);
    printall(stus);
    return 0;
}

void creat(deque<STUDENT>& stu, int num) {
    string name_seed = "ABCDE";
    for (int i = 0; i < num; ++i) 
    {
        stu.push_back(STUDENT(string("选手") + name_seed[i]));
        for (int j = 0; j < 10; ++j) 
        {
            stu.at(i).scores.push_back(rand() % (40 + 1) + 60);
        }
        sort(stu.at(i).scores.begin(), stu.at(i).scores.end());
        stu.at(i).scores.pop_back();
        stu.at(i).scores.erase(stu.at(i).scores.begin());
    }
}

void printall(deque<STUDENT>& p)
{
    double temp = 0.0;
    for (deque<STUDENT>::iterator it = p.begin(); it < p.end() ; ++it)
    {
        cout << it->name << "\t:" << endl;
        temp = 0;
        for (vector<int>::iterator v_it = it->scores.begin() ; v_it < it->scores.end() ; ++v_it)
        {
            temp += *v_it;
            cout << *v_it << " ";
        }
        it->arge_score = temp / it->scores.size();
        cout << endl;
        cout << "arge = " << it->arge_score << endl;
    }
    return;
}