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
Node* middle_linkedlist(Node *head)
{
    Node *ptr1= head;
    Node *ptr2= head;
    Node *p= head;
    Node *q= head->next;
    int i = 0;
    while (ptr1!= NULL)
    {
        ptr1 = ptr1->next;
        i++;
    };
    cout<<i<<endl;
    int size=i/2;
    int j=0;
    while (ptr1!=NULL)
    { 
        if(size==j){
         ptr2=p->next;
         delete p;
         break;

        }
        j++;
        p=p->next;
        q=q->next;
        ptr1=ptr1->next;
    };
    return ptr2;
    
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

    head=middle_linkedlist(head);
    traversal(head);
    return 0;
}