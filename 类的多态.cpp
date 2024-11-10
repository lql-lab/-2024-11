# include <iostream>
using namespace std;

class Ab_cpu
{
public:
    // 虚函数，其实是一个指向函数的指针，会被同名函数掩盖，方便派生类的重写。
    virtual void calcul() = 0;
    // 虚析构，同上，可以避免派生类的析构函数被遮盖。
    virtual ~Ab_cpu()
    {
        cout << "Ab_cpu is die" << endl;
    }
    // 含有虚函数或者虚析构的类称为抽象类，只作为一个访问子类的接口，不能拥有自己的实例。
};
class I_cpu :public Ab_cpu
{
public:
    virtual void calcul()
    {
        cout << "cpu is working" << endl;
    }
    virtual ~I_cpu()
    {
        cout << "I_cpu is die" << endl;
    }
};
class memmer
{
public:
    virtual void member() = 0;
    virtual ~memmer()
    {
        cout << "memmer is die" << endl;
    }
};
class I_mem :public memmer
{
public:
    virtual void member()
    {
        cout << "I_mem is working" << endl;
    }
    virtual ~I_mem()
    {
        cout << "I_mem is die" << endl;
    }
};
class computer
{
public:
    Ab_cpu *cpu;
    memmer *mem;
public:
    computer(Ab_cpu* cpu, memmer * mem)
    {
        this->cpu = cpu;
        this->mem = mem;
    }
    virtual void work()
    {
        cpu->calcul();
        mem->member();
    }
    virtual ~computer()
    {
        if (cpu != NULL)
        {
            delete cpu;
        }
        if (mem != NULL)
        {
            delete mem;
        }
        cout << "computer is die" << endl;
    }
};
void work(Ab_cpu* cpu, memmer* mem)
{
    computer *com = new computer(cpu, mem);
    com->work();
    delete com;   
}
int main()
{
    // 基类的指针是可以向上兼容指向一个子类的。
    work(new I_cpu(), new I_mem());
    return 0;
}