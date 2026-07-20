#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void traversal(Node*ptr){
    while(ptr!=NULL){
        cout<<"ELEMENT:"<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
int node_counter(Node*head){
    Node*ptr=head;
    int i=4;
    while(ptr!=NULL){
     ptr=ptr->next;
     i++;
    
    };
    return i;
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

    traversal(head);
    int result=node_counter(head);
    cout<<"NODES:" <<result;

    return 0;
}