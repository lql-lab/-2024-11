# include <iostream>

class ADK
{
public:
    int capacity, top_of_ADK;
    int* p;
    ADK(int max_elements)
    {
        if (max_elements < 0)
        {
            throw std::runtime_error("min");
        }
        this->capacity = max_elements;
        this->p = new int[max_elements];
        if (p == NULL)
        {
            throw std::runtime_error("out of space");
        }
        this->top_of_ADK = -1;
    }
    bool is_empty()
    {
        return top_of_ADK == -1;
    }
    bool is_full()
    {
        return top_of_ADK == capacity - 1;
    }
    void push(int element)
    {
        if (is_full())
        {
            throw std::runtime_error("out of space");
        }
        p[++top_of_ADK] = element;            
    }
    bool pop()
    {
        if (! is_empty())
        {
            --this->top_of_ADK;
            return true;        
        }
        return false;
    }
    int top()
    {
        if (! is_empty())
        {
            return this->p[this->top_of_ADK];
        }
        return 0;
    }
    int top_pop()
    {
        if (! is_empty())
        {
            return this->p[this->top_of_ADK--];            
        }
        return 0;
    }
    void empty()
    {
        this->top_of_ADK = -1;
        p = NULL;
    }
    void clear()
    {
        delete[] p;
        this->top_of_ADK = -1;
    }
};