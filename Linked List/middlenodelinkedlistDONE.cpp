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
    Node *ptr1=head;
    Node *p= head;
    Node *q= head->next;
    if(ptr1->next==NULL){
        return head;
    }
    int i = 0;
    while (ptr1!= NULL)
    {
        ptr1 = ptr1->next;
        i++;
    };
    cout<<i<<endl;
    int size=i/2;
    int j=1;
    while (q!=NULL)
    { 
        if(size==j){
            return q;
        }
        j++;
        p=p->next;
        q=q->next;
    };
    return q;
    
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
    head->data = 1;
    head->next = first;
    // first
    first->data = 2;
    first->next = second;
    // second
    second->data = 3;
    second->next = third;
    // third
    third->data = 4;
    third->next = fourth;
     fourth->data = 5;
    fourth->next = NULL;
  
  
    head=middle_linkedlist(head);
    traversal(head);
    return 0;
}