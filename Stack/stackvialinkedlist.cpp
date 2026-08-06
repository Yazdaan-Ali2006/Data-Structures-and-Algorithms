#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void traversal(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
bool isFull(Node *top)
{
    Node *p = new Node;
    if (p == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty(Node *top)
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Node *push(Node *top, int n)
{
    if (isFull(top))
    {
        cout << "STACK IS FULL.." << endl;
    }
    else
    {
        Node *p = new Node;
        p->data = n;
        p->next = top;
        top = p;
        cout << "SUCCESFULLY PUSHED:" << n << endl;
    }
    return top;
}
Node* pop(Node *top)
{
    if (isEmpty(top))
    {
        cout << "STACK IS EMPTY..." << endl;
    }
    else
    {
        Node *temp = top;
        cout << "TOP DELETED WITH ELEMTENT:" << top->data << endl;
        top = top->next;
        delete temp;
    }
    return top;
}
int main()
{
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    cout << "Original Linkedlist" << endl;
    traversal(first);
    cout << "AFTER PUSHING" << endl;
    first = push(first, 100);
    traversal(first);
   first= pop(first);
    traversal(first);

    return 0;
}