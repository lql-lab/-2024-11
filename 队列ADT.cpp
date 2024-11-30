# include <iostream>

class QUEUE_ADT
{
public:
    int size = 0, front, rear, capacity;
    int *p = NULL;
    QUEUE_ADT(int capacity) :capacity(capacity)
    {
        if(capacity <= 0)
        {
            throw std::runtime_error("too small");
        }
        p = new int[capacity];
        front = size = 0;
        rear = -1;
    }
    void operator=(QUEUE_ADT& q)
    {
        size = 0;
        capacity = q.capacity;        
        front = q.front;    rear = q.rear;
        p = new int[capacity];
        if (!q.is_empty())
        {
            for (int i = 0,j = q.front, num = 0; num < q.size; ++i, ++j, ++num)
            {
                if (j >= capacity)
                {
                    j = 0;
                }
                p[i] = q.p[j];
            }    
        }
    }
    QUEUE_ADT(QUEUE_ADT& q)
    {
        // size = 0;
        // capacity = q.capacity;        
        // front = q.front;    rear = q.rear;
        // p = new int[capacity];
        // if (!q.is_empty())
        // {
        //     for (int i = 0,j = q.front, num = 0; num < q.size; ++i, ++j, ++num)
        //     {
        //         if (j >= capacity)
        //         {
        //             j = 0;
        //         }
        //         p[i] = q.p[j];
        //     }    
        // }
        *this = q;
    }
    ~QUEUE_ADT()
    {
        delete[] p;
    }
    bool is_empty()
    {
        return size == 0;
    }
    bool is_full()
    {
        return size == capacity;
    }
    int enqueue(int element)
    {
        if (is_full())
        {
            throw std::runtime_error("out of range");
        }
        ++size;    ++rear;
        if (rear >= capacity)
        {
            rear = 0;
        }
        p[rear] = element;
        return element;
    }
    int dequeue()
    {
        if (is_empty())
        {
            throw std::runtime_error("is empty");
        }
        --size;
        if (front >= capacity)
        {
            front = 0;
        }
        return p[front++];
    }
    void empty()
    {
        size = front = 0;
        rear = -1;
    }
    void clear()
    {
        delete[] p;
        p = NULL;
    }
};