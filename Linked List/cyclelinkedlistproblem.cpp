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
bool cyclic_linkedlist(Node *head, int pos)
{
    Node *ptr1 = head; // To reach till last node
    Node *current_node = head;
    Node *check_node = head;
    int i = 0;
    int j = 0;
    int k = 0;
    while (ptr1 != NULL)
    {
        ptr1 = ptr1->next;
        i++; // we got the size of linkedlist
    }
    while (j <= i)
    {
        current_node = current_node->next; // reached the last node
        j++;
    }
    // checking for cycle
    while (k <= pos)
    {
        check_node = check_node->next;
        if (current_node->next == check_node)
        {
            return true;
        }
    }
    return false;
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
    fourth->next = second;
    traversal(head);
    return 0;
}