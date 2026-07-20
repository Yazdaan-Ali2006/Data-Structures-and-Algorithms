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
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    };
}
Node *sort(Node *head, int size)
{

    int temp;
    int i = 0;

    while (i != size)
    {
        Node *p = head;
        Node *q = head->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            p = p->next;
            q = q->next;
        }
        i++;
    }

    return head;
}
int main()
{
    Node *head = new Node;
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *final = new Node;

    // HEAD
    head->data = 200;
    head->next = first;

    // FIRST
    first->data = 2020;
    first->next = second;

    // SECOND
    second->data = 80;
    second->next = third;

    // THIRD
    third->data = 70;
    third->next = final;

    // FOURTH
    final->data = 12;
    final->next = NULL;

    cout << "BEFORE SORTING" << endl;
    traversal(head);

    cout << "AFTER SORTING" << endl;
    head = sort(head, 5);
    traversal(head);

    return 0;
}