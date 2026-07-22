#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void traversal(Node *head)
{
    int i = 1;
    Node *ptr = head;
    do
    {
        cout << "ELEMENT[" << i << "]:" << ptr->data << endl;
        ptr = ptr->next;
        i++;
    } while (ptr != head);
}
// CASE 1
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
// CASE 2
Node *insert_at_last(Node *head, int element)
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
    return head;
}
// CASE 3
Node *insert_at_index(Node *head, int index, int element)
{
    Node *ptr1 = head;
    Node *ptr2 = NULL;
    Node *p = new Node;
    p->data = element;
    int i = 0;
    do
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;

        i++;
        if (i == index)
        {
            break;
        }
    } while (ptr1->next != head);
    p->next = ptr1;
    ptr2->next = p;
    return head;
}
// CASE 4
Node *insert_after_node(Node *head, Node *node, int element)
{
    Node *ptr1 = head;
    Node *ptr2 = NULL;
    Node *q = new Node;
    q->data = element;
    do
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;

    } while (ptr1 != node);

    q->next = ptr1->next;
    ptr1->next = q;
    return head;
}

// DELETION
// case 1
Node *delete_first_node(Node *head)
{
    Node *q = head;
    do
    {
        q = q->next;

    } while (q->next != head);
    q->next = head->next;
    delete head;
    return q->next;
}

// case 2;
Node *delete_last_node(Node *head)
{

    Node *p = head;
    Node *q = NULL;
    do
    {
        q = p;
        p = p->next;

    } while (p != head);
    q->next = p->next;
    delete p;
    return q->next;
}
// case 3
Node *delete_after_node(Node *head, Node *node)
{
    Node *p = head;
    Node *q = head->next;
    Node *r = node;
    do
    {
        p = p->next;
        q = q->next;
    } while (p->next != node);
    p->next = q->next;
    delete q;
    return head;
}
Node *delete_at_index(Node *head, int index)
{
    Node *p = head;
    Node *q = NULL;

    int i = 0;

    while (i != index)
    {
        q = p;
        p = p->next;

        i++;
    }
    q->next = p->next;
    delete p;
    return head;
}
int main()
{

    Node *head;
    Node *first;
    Node *second;
    Node *third;
    Node *fourth;
    head = new Node;
    first = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
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
    third->next = fourth;
    // fourth
    fourth->data = 211;
    fourth->next = head;

    cout << "CIRCULAR LINKEDLIST..." << endl;
    traversal(head);

    // cout << "INSERTING A NEW HEAD..." << endl;
    // head = insert_at_first(head, 89);
    // traversal(head);

    // cout << "INSERTION AT LAST..." << endl;
    // head = insert_at_last(head, 10291);
    // traversal(head);

    // cout << "INSERTION AT INDEX.." << endl;
    // head = insert_at_index(head, 2, 1241);
    // traversal(head);

    // cout << "INSERTION AFTER A NODE.." << endl;
    // head = insert_after_node(head, first, 431221);
    // traversal(head);

    // cout << "DELET FIRST NODE...." << endl;
    // head = delete_first_node(head);
    // traversal(head);

    // cout << "DELETE LAST NODE...." << endl;
    // head = delete_last_node(head);
    // traversal(head);

    cout << "DELETE AFTER THIS  NODE...." << endl;
    head = delete_after_node(head, second);
    traversal(head);

    cout << "DELETE INDEX...." << endl;
    head = delete_at_index(head, 2);
    traversal(head);

    return 0;
}