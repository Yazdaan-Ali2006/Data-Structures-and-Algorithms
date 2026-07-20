#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void traversal(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << "ELEMENT:" << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}
Node *insert_at_first(Node *head, int element)
{
    Node *ptr = new Node;
    ptr->data = element;
    Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{

    Node *head;
    Node *first;
    Node *second;
    Node *third;
    head = new Node;
    first = new Node;
    second = new Node;
    third = new Node;
    // head
    head->data = 8;
    head->next = first;
    // first
    first->data = 10;
    first->next = second;
    // second
    second->data = 12;
    second->next = third;
    // third
    third->data = 15;
    third->next = head;

    traversal(head);
    head=insert_at_first(head,89);
    traversal(head);


    return 0;
}