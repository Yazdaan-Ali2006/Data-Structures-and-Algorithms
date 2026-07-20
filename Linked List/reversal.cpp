#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
void traversal(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << "ELEMENT: " << p->data << endl;
        p = p->link;
    };
}
Node *reverse_linkedlist(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->link;

        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main()
{
    Node *head = new Node;
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    head->data = 1;
    head->link = first;
    first->data = 2;
    first->link = second;
    second->data = 3;
    second->link = third;
    third->data = 4;
    third->link = NULL;
    cout << "BEFORE REVERSING" << endl;
    traversal(head);
    cout << "AFTER REVERSING" << endl;
    head = reverse_linkedlist(head);
    traversal(head);
    return 0;
}