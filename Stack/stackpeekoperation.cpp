#include <iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    int *arr;
};
int peek(stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        cout << "CANNOT PEEK" << endl;
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    } 
    else
    {
        return 0;
    }
}
void push(stack *ptr, int val)
{
    if (isFull(ptr) == 1)
    {
        cout << "STACK IS FULL..." << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        cout << val << " INSERTED..." << endl;
    }
}

int pop(stack *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        cout << "STACK IS EMPTY..." << endl;
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main()
{
    stack *s = new stack;
    s->size = 5;
    s->top = -1;
    s->arr = new int[s->size];
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << "Popped:"<<pop(s) << endl;
    cout << "Popped:"<<pop(s) << endl;

    for (int j = 1; j <= s->top+1; j++)
    {
        cout << "ELEMENT NO." << j << ":" << peek(s, j) << endl;
    }

    return 0;
}