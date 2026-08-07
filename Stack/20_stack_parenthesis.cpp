#include <iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    char *arr;
};
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
void push(stack *ptr, char val)
{
    if (isFull(ptr) == 1)
    {
        cout << "STACK IS FULL..." << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        cout << "INSERTED..." << endl;
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
bool parenthesis(const char *p)
{
    stack *sp = new stack;
    sp->top = -1;
    sp->size = 100;
    sp->arr = new char[sp->size];
    for (int i = 0; p[i] != '\0'; i++)
    {
        if ((p[i] == '(') || (p[i] == '[') || (p[i] == '{'))
        {
            push(sp, p[i]);
        }
        else if (
            (p[i] == ')' && sp->arr[sp->top] == '(') || (p[i] == '}' && sp->arr[sp->top] == '{') || (p[i] == ']' && sp->arr[sp->top] == '['))
        {
            if (isEmpty(sp))
            {
                return false;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return true;
    }
    return false;
}
int main()
{
    // stack *s = new stack;
    // s->size = 3;
    // s->top = -1;
    // s->arr = new char[s->size];
    // push(s, 1);
    // push(s, 2);
    // push(s, 3);
    // cout << pop(s) << endl;
    // cout << pop(s) << endl;
    // cout << pop(s) << endl;
    const char *ch = "[{()}]";
    if (parenthesis(ch))
    {
        cout << "PARENTHESIS MATCHING" << endl;
    }
    else
    {
        cout << "PARENTHESIS NOT MATCHING" << endl;
    }

    return 0;
}