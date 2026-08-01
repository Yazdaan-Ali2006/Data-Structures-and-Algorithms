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

Node *merge_linkedlist(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data <= head2->data)
    {
        head1->next = merge_linkedlist(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = merge_linkedlist(head1, head2->next);
        
            return head2;
        
    }
}

int main()
{
    // First Linked List: 1 -> 2 -> 4
    Node *head1 = new Node;
    Node *first1 = new Node;
    Node *second1 = new Node;

    head1->data = 1;
    head1->next = first1;

    first1->data = 2;
    first1->next = second1;

    second1->data = 4;
    second1->next = NULL;

    // Second Linked List: 1 -> 3 -> 4
    Node *head2 = new Node;
    Node *first2 = new Node;
    Node *second2 = new Node;

    head2->data = 1;
    head2->next = first2;

    first2->data = 3;
    first2->next = second2;

    second2->data = 4;
    second2->next = NULL;

    cout << "List 1:" << endl;
    traversal(head1);

    cout << "List 2:" << endl;
    traversal(head2);

    cout << "MERGING.." << endl;
    head1 = merge_linkedlist(head1, head2);
    traversal(head1);

    return 0;

    return 0;
}