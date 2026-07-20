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

        cout << "ELEMENT:" << ptr->data << endl;
        ptr = ptr->next;
    };
}
// CASE 1
Node *delete_head(Node *head)
{
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};
// CASE 2
Node *delete_value(Node *head, int value)
{
    Node *ptr1 = head;
    Node *ptr2 = head->next;
    while (ptr2->data != value)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    };
    ptr1->next = ptr2->next;
    delete (ptr2);
    return head;
}
// CASE 3
Node *delete_last_node(Node *head)
{
    Node *ptr1 = head;
    Node *ptr2 = head->next;
    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL;
    delete ptr2;
    return head;
}
// CASE 4
Node *delete_at_index(Node *head, int index)
{
    Node *ptr1 = head;
    Node *ptr2 = head->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        i++;
    }
    ptr1->next = ptr2->next;
    delete ptr2;
    return head;
}
int main()
{
    Node *head = new Node;
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    // HEAD
    head->data = 100;
    head->next = first;
    // FIRST
    first->data = 200;
    first->next = second;
    // SECOND
    second->data = 400;
    second->next = third;
    // THIRD
    third->data = 1210;
    third->next = fourth;
    // fourth
    fourth->data = 1921;
    fourth->next = NULL;
    cout << "ALL DATA OF LINKEDLIST" << endl;
    traversal(head);
    // cout<<"AFTER DELETING HEAD"<<endl;
    //  head = delete_head(head);
     // traversal(head);
   

    // cout<<"DELETING AT INDEX"<<endl;
    // head=delete_at_index(head,2);
    // traversal(head);


    // cout << "AFTER DELETING LAST NODE" << endl;
    // head = delete_last_node(head);
    // traversal(head);
   
   
    // cout << "AFTER DELETING A SPECIFIC VALUE" << endl;
    // head = delete_value(head, 1210);
    // traversal(head);

    return 0;
}
