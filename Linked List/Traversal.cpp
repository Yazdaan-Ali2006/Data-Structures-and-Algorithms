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

    return 0;
}