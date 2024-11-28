# include <iostream>

template<typename T>
class NODE
{
public:
    NODE<T> *next;
    NODE<T> *prev;
    NODE<T> *child_n;
    NODE<T> *child_p;
    T element;
    NODE(T ele)
    {
        this->element = ele;
    }
    bool islast()
    {
        return next;
    }
    T operator=(NODE<T> &node)
    {
        T temp = node.element;
        node.element = this->element;
        this->element = temp;
        return temp;
    }
};
template<typename T>
class LIST
{    
public:    
    NODE<T> *head;
    LIST()
    {
        head = NULL;
    }
    bool isempty()
    {
        return head;
    }
    void insert(T element)
    {
        NODE<T> *p = new NODE<T>(element);
        if (!isempty())
        {
            p->prev = p->next = head = p;
        }
        else
        {
            p->next = head->next;
            p->prev = head;
            head->next = head->next->prev = p;
            head = p;
        }
        p->child_n = p->child_p = p;
    }
    void insertchild(T element, NODE<T> *p)
    {
        NODE<T> *q = new NODE<T>(element);
        if (p == NULL)
        {
            insert(element);
            return;
        }
        else
        {
            q->child_n = p->child_n;
            q->child_p = p;
            p->child_n->child_p = q;
            p->child_n = q;
        }
    }
    void printlist(int i = 0)
    {
        NODE<T> *p = head;
        if (!isempty())
        {
            return;
        }
        if (i = 0)
        {
            do
            {
                std::cout << p->next->element << std::endl;
                p = p->next;
            } while (p != head);    
        }
        else
        {
            do
            {
                std::cout << p->element << std::endl;
                p = p->prev;
            } while (p != head);    
        }
    }
    void print_childlist(NODE<T> *p)
    {
        if (!p)
        {
            return;
        }
        NODE<T> *q = p;
        do
        {
            std::cout << p->element << std::endl;
            p = p->child_n;
        } while (p != q);    
    }
    NODE<T>* find(T element)
    {
        NODE<T> *p = head;
        while (p->element != element)
        {
            p = p->next;
            if (p == head)
            {
                return NULL;
            }
        }
        return p;
    }
    NODE<T>* find_child(T element, NODE<T> *p)
    {
        NODE<T> *q = p;
        while (p->element != element)
        {
            p = p->child_n;
            if (p == q)
            {
                return NULL;
            }
        }
        return p;
    }
    void delet(T element)
    {
        NODE<T> *p = find(element);
        if(p)
        {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            NODE<T> *q = p->child_n;
            while (q != p)
            {
                NODE<T> *r = q->child_n;
                delete q;
                q = r;
            }
            delete p;
        }
    } 
    void delet(NODE<T> *p)
    {
        if(p)
        {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            NODE<T> *q = p->child_n;
            while (q != p)
            {
                NODE<T> *r = q->child_n;
                delete q;
                q = r;
            }
            delete p;
        }
    }
    void clear()
    {
        NODE<T> *p = head;
        if (!isempty())
        {
            while (p != NULL)
            {
                NODE<T> *q = p->next;
                NODE<T> *s = p->child_n;
                while (s != NULL)
                {
                    NODE<T> *r = s->child_n;
                    delete s;
                    s = r;
                }
                p = q;
            } 
        }
        
    }
};

int main()
{
    LIST<int> lis;
    std::cout << lis.isempty() << std::endl;
    lis.insert(1);
    lis.insert(2);
    lis.insert(3);
    lis.insert(4);
    lis.insert(5);
    lis.printlist(1);
    std::cout << lis.find(5) << std::endl;
    lis.delet(3);
    lis.printlist();
    std::cout << std::endl;
    lis.insertchild(2, lis.head);
    lis.insertchild(3, lis.head);
    lis.insertchild(4, lis.head);
    std::cout << lis.find_child(2, lis.head) << std::endl;
    lis.print_childlist(lis.head);
    lis.clear();
    return 0;
}