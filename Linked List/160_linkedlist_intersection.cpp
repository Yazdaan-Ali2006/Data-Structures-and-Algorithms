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
Node *intersection(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    int size1 = sizeoflinkedlist(head1);
    int size2 = sizeoflinkedlist(head2);
    int diff;
    if (size1 > size2)
    {
        diff = size1 - size2;
    }
    else if (size2 > size1)
    {
        diff = size2 - size1;
    }
    else
    {
        diff = 0;
    }
    if (diff == 0)
    {

        Node *p = head1;
        Node *q = head2;

        while (p != q)
        {
            if (p == NULL || q == NULL)
            {
                return NULL;
            }
            p = p->next;
            q = q->next;
        }
        return p;
    }
    else if (size1 > size2)
    {
        Node *p = head1;
        Node *q = head2;
        int i = 0;
        while (i != diff)
        {
            i++;
            p = p->next;
        }
        while (p != q)
        {
            if (p == NULL || q == NULL)
            {
                return NULL;
            }
            p = p->next;
            q = q->next;
        }
        return p;
    }
    else
    {
        Node *p = head1;
        Node *q = head2;
        int i = 0;
        while (i != diff)
        {
            i++;
            q = q->next;
        }
        while (p != q)
        {
            if (p == NULL || q == NULL)
            {
                return NULL;
            }
            p = p->next;
            q = q->next;
        }
        return p;
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

    // Second Linked List: 1 -> 3 -> 4
    Node *head2 = new Node;
    Node *first2 = new Node;
 

    head2->data = 1;
    head2->next = first2;

    first2->data = 3;
   

    

    // Third Linked List
    Node *head3 = new Node;
    Node *first3 = new Node;
    Node *second3 = new Node;

    head3->data = 21;
    head3->next = first3;

    first3->data = 23;
    first3->next = second3;

    second3->data = 2121;
    second3->next = NULL;

    // intersection point
    second1->next = head3;
 first2->next = head3;

    cout << "List 1:" << endl;
    traversal(head1);

    cout << "List 2:" << endl;
    traversal(head2);

    cout << sizeoflinkedlist(head1) << endl;
    cout << sizeoflinkedlist(head2) << endl;
    cout << "Intersection:" << endl;
    head1 = intersection(head1, head2);
     cout<<head1->data;
    return 0;

    return 0;
}