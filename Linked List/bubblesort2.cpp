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
        cout << "ELEMENT: " << ptr->data << endl;
        ptr = ptr->next;
        
    }
    cout<<endl; 
}
Node *bubble_sort(Node *head, int size)
{
    int temp;
    int i = 0;
    while (i != size)
    {
        Node *ptr1 = head;
        Node *ptr2 = head->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        i++;
    }
    return head;
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
    //AFTER SORTING
    head=bubble_sort(head,5);
    traversal(head);

    return 0;
}