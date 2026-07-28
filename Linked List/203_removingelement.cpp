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
Node *delete_node(Node *head, int val)
{
    while (head != NULL && head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    if (head == NULL)
    {
        return NULL;
    }
    
    Node *p = head;
    Node *q = head->next;
    while (q != NULL)
    {
        if (q->data == val)
        {         Node *temp = q;
            p->next = q->next;
            q=q->next;
            delete temp;
        }
    else{
        p = q;
        q = q->next;}
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

    second->data = 3;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = NULL;

    traversal(head);

    cout << "after attempting to delete" << endl;
    head = delete_node(head, 2);
    traversal(head);

    return 0;
}