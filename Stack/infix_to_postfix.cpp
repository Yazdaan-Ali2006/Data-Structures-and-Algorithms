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
int precedence(char ch)
{
    if (ch == '/' || ch == '*')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return true;
    }

    return false;
}

char *infix_to_postfix(char *infix)
{
    stack *sp = new stack;

    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];

    char *postfix = new char[100];

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(sp->arr[sp->top]))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';

    return postfix;
}
int main()
{
    char *ch="a-bt/6";
    cout<<"POST FIX:"<<infix_to_postfix(ch)<<endl;


    return 0;
}