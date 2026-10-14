#include <iostream>
using namespace std;
template <class T>
class stack
{
private:
    int tos;
    int maxstack;
    T *arr;

public:
    stack(int size)
    {
        tos = -1;
        maxstack = size;
        arr = new T[maxstack];
    }
    void makeempty()
    {
        tos = -1;
    }
    void makefull()
    {
        tos = maxstack - 1;
    }
    bool isempty()
    {
        return (tos == -1);
    }
    bool isfull()
    {
        return (tos == maxstack - 1);
    }
    void push(T x)
    {
        if (isfull())
        {
            cout << "Stack is Full" << endl;
        }
        else
        {
            tos++;
            arr[tos] = x;
        }
    }
    T pop()
    {
        if (isempty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        else
        {
            T temp;
            temp = arr[tos];
            tos--;
            return temp;
        }
    }
    ~stack()
    {
        delete[] arr;
    }

    /*
    class stack{
    private:
    int tos;
    int maxstack;
    int*arr;
    public:
    stack(int size){
    maxstack=size;
    int tos=-1;
    arr=new int[maxstack];
    bool isempty(){
      return(tos==-1);
    }
    void isempty(){
     tos=-1;
    };
    bool isfull(){
    return (tos==-1);
    }
    void isfull(){
    tos=maxstack-1;
    ~stack(){
    delete[]arr;
    }
    
    };
    */
};

int main()
{
    stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(5);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}