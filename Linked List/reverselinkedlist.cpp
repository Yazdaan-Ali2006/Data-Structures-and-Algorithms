#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void traversal(Node *head)
{
    int i = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << "ELEMENT(" << i + 1 << "): " << ptr->data << endl;
        ptr = ptr->next;
        i++;
    }
    cout << endl;
}
Node *reverse_linkedlist(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
   
    while (current!=NULL)
    {  
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        
    }
    return prev;
}
int main()
{
    Node *head = new Node;
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    // HEAD..
    head->data = 291;
    head->next = first;

    // FIRST..
    first->data = 672;
    first->next = second;

    // SECOND..
    second->data = 21344;
    second->next = third;

    // THIRD
    third->data = 28182;
    third->next = fourth;

    // FOURTH
    fourth->data = 122;
    fourth->next = NULL;
    // BEFORE SORTING
    traversal(head);
    head=reverse_linkedlist(head);
    traversal(head);

    return 0;
}