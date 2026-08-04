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
int sizeoflinkedlist(Node *head)
{
    Node *p = head;
    int i = 0;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}
Node *deleteNthnode(Node *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    int size = sizeoflinkedlist(head);
    int diff = size - n;
    if(size==1){
        return NULL;
    }
    if (diff == 0)
    {
        Node *p = head;
        head= head->next;
        delete p;
        return head;
    }
    else
    {
        Node *p = head;
        Node *q = head->next;
        Node *temp = NULL;
        int i = size-1;
        while (i != n)
        {
            p = p->next;
            q = q->next;
            i--;
        }
        temp = q;
        p->next = q->next;
        delete temp;
        return head;
    }
}

int main()
{
    // First Linked List: 1 -> 2 -> 4
    Node *head1 = new Node;
    Node *first1 = new Node;
    Node *second1 = new Node;
    Node *third1 = new Node;
    Node *fourth1 = new Node;
    Node *fifth1 = new Node;

    head1->data = 1;
    head1->next = first1;

    first1->data = 2;
    first1->next = second1;

    second1->data = 4;
    second1->next = third1;

    third1->data = 3;
    third1->next = fourth1;

    fourth1->data = 6;
    fourth1->next = fifth1;

    fifth1->data = 11;
    fifth1->next = NULL;

    cout << "List 1:" << endl;
    traversal(head1);
    cout<<"AFTER DELETING NTH NODE"<<endl;
    head1 = deleteNthnode(head1, 2);
    traversal(head1);

    return 0;
}