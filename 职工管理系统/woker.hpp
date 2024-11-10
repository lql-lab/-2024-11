# pragma once
# include <iostream>
using namespace std;

class Ab_woker
{
public:
    virtual void show_massage() = 0;
    virtual ~Ab_woker()
    {

    }
public:
    string name;
    string job;
    int num;
};

class worker :public Ab_woker
{
public:
    void show_massage()
    {
        cout << name << "\t";
        cout << job << "\t";
        cout << num << endl;
    }
    worker()
    {
        job = "员工";
    }
    worker(string name, int num)
    {
        job = "员工";
        this->name = name;
        this->num = num;
    }
    ~worker()
    {

    }
};
class boss :public Ab_woker
{
public:
    int* arr[100];
    int worker_num;
    void show_massage()
    {
        cout << name << "\t";
        cout << job << "\t";
        cout << num << endl;
    }
    boss()
    {
        job = "老板";
        worker_num = 0;
    }
    boss(string name, int num)
    {
        worker_num = 0;
        job = "老板";
        this->name = name;
        this->num = num;
    }
    ~boss()
    {
        
    }
};