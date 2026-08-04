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
void deletenode(Node *p)
{
    p->data = p->next->data;
    Node *temp = p->next;
    p->next = temp->next;
    delete temp;
}

int main()
{

    Node *first1 = new Node;
    Node *second1 = new Node;
    Node *third1 = new Node;
    Node *fourth1 = new Node;
    Node *fifth1 = new Node;



    first1->data = 8;
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
    traversal(first1);
    deletenode(second1);
    cout << "AFTER DELETION" << endl;

    traversal(first1);

    return 0;
}
