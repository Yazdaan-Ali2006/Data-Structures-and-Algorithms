#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void traversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "ELEMENT:" << ptr->data << endl;
        ptr = ptr->next;
    }
}
Node *insert_before_head(Node *head, int element)
{
    Node *ptr = new Node;
    ptr->data = element;
    ptr->next = head;
    return ptr;
}

Node *insert_at_index(Node *head, int element, int index)
{
    Node *ptr = new Node;
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    };
    ptr->data = element;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
Node *insert_at_end(Node *head, int element)
{
    Node *ptr = new Node;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = element;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
Node *insert_after_a_node(Node *head, Node *p, int element)
{
    Node *ptr = new Node;
    ptr->data = element;
    ptr->next = p->next;
    p->next = ptr;
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
    third->next = NULL;
    // cout << "NORMAL TRAVERSAL" << endl;
    // traversal(head);
    // cout << "AFTER ADDING BEFOR HEAD" << endl;
    // head = insert_before_head(head, 100);
    // traversal(head);
    // cout << "INSERTION IN BETWEEN" << endl;
    // head = insert_at_index(head, 3000, 2);
    // traversal(head);
    // cout << "INSERTION AT END" << endl;
    // head = insert_at_end(head, 192);
    // traversal(head);
    cout << "INSERTION AFTER NODE" << endl;
    head = insert_after_a_node(head, second, 292);
    traversal(head);

    return 0;
}