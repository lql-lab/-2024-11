# pragma once
# include <iostream>
using namespace std;
# include "woker.hpp"
# include <string>

struct AW
{
    Ab_woker* man;
    struct AW* next;
    struct AW* last; 
};

class WM
{
public:
    int man_num;
    AW* first;
    AW* end;
    WM();
    ~WM();
    void quit();
    void show_mune();
    void add_mans();
    void show_mans();
    AW* find_mans(int num);
    AW* find_mans(string name);
    void del_mans(int num);
    void del_mans(string name);
    void catch_find(int num);
    void catch_find(string name);
    void redefine(string name);
    void redefine(int num);
    void sort();
    void clear();
};
    WM::WM()
    {
        man_num = 0;
        first = NULL;
        end = NULL;
    }
    WM::~WM()
    {
        for(AW* p = first;p != NULL;)
        {
            AW* q = p->next;
            delete p->man;
            delete p;
            p = q;
        }
    }
    void WM::show_mune()
    {
        cout << "0.退出" << endl;
        cout << "1.添加" << endl;
        cout << "2.显示" << endl;
        cout << "3.删除" << endl;
        cout << "4.查找" << endl;
        cout << "5.修改" << endl;
        cout << "6.排序" << endl;
        cout << "7.清空" << endl;
    }
    void WM::quit()
    {
        cout << "退出" << endl;
        exit(0);
    }
    void WM::add_mans()
    {
        int add_num = 0;
        cout << "人数：" << endl;
        cin >> add_num;
        for(int i = 0;i < add_num;i++)
        {
            string type;
            AW* new_one = new AW();
            cout << "输入职位：" << endl;
            cin >> type;
            if (type == "员工")
            {
                new_one->man = new worker();
            }
            else if(type == "老板")
            {
                new_one->man = new boss();
            }
            cout << "输入名字：" << endl;
            cin >> new_one->man->name;
            cout << "输入编号：" << endl;
            cin >> new_one->man->num;
            if (first == NULL)
            {
                first = new_one;
                first->last = NULL;
                first->next = NULL;
            }
            else if(end == NULL)
            {
                first->next = new_one;
                end = new_one;
                end->last = first;
                end->next = NULL;
            }
            else
            {
                new_one->last = end;
                new_one->next = NULL;
                end->next = new_one;
                end = new_one;
            }
        }
        if (add_num > 0)
        {
            man_num += add_num; 
        }
    }
    void WM::show_mans()
    {
        for(AW *p = first; p != NULL; p = p->next)
        {
            p->man->show_massage();
        }
    }
    AW* WM::find_mans(int num)
    {
        AW* q = NULL;
        for(AW* p = first; p != NULL; p = p->next)
        {
            if (p->man->num == num)
            {
                q = p;
                break;
            }
        }
        return q;
    }
    AW* WM::find_mans(string name)
    {
        AW* q = NULL;
        for(AW* p = first; p != NULL; p = p->next)
        {
            if (p->man->name == name)
            {
                q = p;
                break;
            }
        }
        return q;        
    }
    void WM::del_mans(int num)
    {
        AW* p = find_mans(num);
        if (p != NULL)
        {
            if (p->last == NULL)
            {
                first = p->next;
                first->last = NULL;
                delete p->man;
                delete p;
                man_num--;
            }
            else if (p->next == NULL)
            {
                end = p->last;
                end->next = NULL;
                delete p->man;
                delete p;
                man_num--;
            }
            else
            {
                p->last->next = p->next;
                p->next->last = p->last;
                delete p->man;
                delete p;
                man_num--;
            }
        }
    }
    void WM::del_mans(string name)
    {
        AW* p = find_mans(name);
        if (p != NULL)
        {
            if (p->last == NULL)
            {
                first = p->next;
                first->last = NULL;
                delete p->man;
                delete p;
                man_num--;
            }
            else if (p->next == NULL)
            {
                end = p->last;
                end->next = NULL;
                delete p->man;
                delete p;
                man_num--;
            }
            else
            {
                p->last->next = p->next;
                p->next->last = p->last;
                delete p->man;
                delete p;
                man_num--;
            }
        }
    }
    void WM::catch_find(int num)
    {
        AW* p = find_mans(num);
        p->man->show_massage(); 
    }
    void WM::catch_find(string name)
    {
        AW* p = find_mans(name);
        p->man->show_massage();
    }
    void WM::redefine(string name)
    {
        AW* p = find_mans(name);
        delete p->man;
        cout << "输入职位：" << endl;
        string job;
        Ab_woker* q = NULL;
        cin >> job;
        if (job == "老板")
        {
            q = new boss();
        }
        else if (job == "员工")
        {
            q = new worker();
        }
        cout << "输入姓名：" << endl;
        cin >> q->name;
        cout << "输入编号：" << endl;
        cin >> q->num;
        p->man = q;
    }
    void WM::redefine(int num)
    {
        AW* p = find_mans(num);
        delete p->man;
        cout << "输入职位：" << endl;
        string job;
        Ab_woker* q = NULL;
        cin >> job;
        if (job == "老板")
        {
            q = new boss();
        }
        else if (job == "员工")
        {
            q = new worker();
        }
        cout << "输入姓名：" << endl;
        cin >> q->name;
        cout << "输入编号：" << endl;
        cin >> q->num;
        p->man = q;
    }
    void swap(AW* p, AW* q)
    {
        Ab_woker* temp = p->man;
        p->man = q->man;
        q->man = temp;
    }
    void WM::sort()
    {
        for (AW* p = first->next; p != NULL ; p = p->next)
        {
            AW* q = p;
            while (q != first && q->last->man->num > q->man->num)
            {
                swap(q, q->last);
                q = q->last;
            }
        }
    }
    void WM::clear()
    {
        for(AW* p = first;p != NULL;)
        {
            AW* q = p->next;
            delete p->man;
            delete p;
            p = q;
        }
        first = NULL;
        end = NULL;
        man_num = 0;
    }
