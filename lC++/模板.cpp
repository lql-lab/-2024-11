# include <iostream>
using namespace std;

// 模板实现了将类名作为一种参数，提高了代码的复用性。
template<typename T>
void swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
template<typename T,typename U>
void func1(T, U)
{

}
template<typename T,typename U>
class Person
{
friend void func1(T,U);
public:
    U u;
    T t;
    void func(U, T);
};
// 模板继承。
template<typename I, typename O, typename P>
class p_Person :public Person<I, O>
{
    P p;
};
// 模板灵活使用。
template<typename T>
void func(Person<T,int>* person)
{

}
template<typename T, typename U>
void Person<T,U>::func(U,T)
{
    cout << endl;
}
int main()
{
    int a = 0;
    int b = 1;
    swap<int>(&a, &b);
    Person<int, int> person;
    person.t = 1;
    person.u = 1;
    func1<int,int>(person.t,person.u);
    return 0;
}