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
Node *remove_duplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *p = head;
    Node *q = head->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            Node *temp = q;
            p->next = q->next;
            q = q->next;
            delete temp;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node;
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = NULL;

    traversal(head);

    cout << "after attempting to delete" << endl;
    head = remove_duplicates(head);
    traversal(head);

    return 0;
}