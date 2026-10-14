#include <iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *next;
};
template <class T>
class stack
{
private:
    node<T> *tos;

public:
    stack()
    {
        tos = NULL;
    }
    bool isFull()
    {
        node<T>*temp = new node<T>;
        if (temp == NULL)
        {
            return true;
        }
        delete temp;
        return false;
    }
    bool isempty()
    {
        return (tos == NULL);
    }
    void make_empty()
    {
        node<T> *temp=tos;
        while (tos != NULL)
        {
            temp = tos;
            tos = tos->next;
            delete temp;
        }
    }
    void push(T x)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {

            node<T> *temp = new node<T>;
            temp->data = x;
            temp->next = tos;
            tos = temp;
        }
    }
    T pop()
    {
        node<T> *temp = tos;
        T info = tos->data;
        tos = tos->next;
        delete temp;
        return info;
    }
    T peakoperation(int position)
    {
        node<T> *temp = tos;
        for (int i = 0; (i < position - 1 && temp != NULL); i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    T stack_bottom()
    {
        node<T> *p = tos;
        while (p->next != NULL)
        {
            p = p->next;
        }
        return p->data;
    }

    ~stack()
    {
        delete[] tos;
    }
};

int main()
{
    stack<int> s;
    cout<<"PUSHING..."<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"PEAK:"<<s.peakoperation(3)<<endl;
    cout<<"STACK_BOTTOM:"<<s.stack_bottom()<<endl;

    cout<<"POPPING..."<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    return 0;
}