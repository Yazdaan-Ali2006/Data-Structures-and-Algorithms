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

int sizeoflinkedlist(Node *head)
{
    Node *p = head;
    int i = 0;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}
Node *reverse_linkedlist(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPallindrome(Node *head)
{
    Node *p = head;

    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // odd skipping middle
    if (fast != NULL)
    {
        slow = slow->next;
    }
    slow = reverse_linkedlist(slow);
    while (slow != NULL)
    {
        if (slow->data != p->data)
        {
            return false;
        }
        slow = slow->next;
        p = p->next;
    }
    return true;
}

Node *rotate(Node *head, int k)
{
    Node *q = head;
    Node *p = head->next;
    Node *temp = NULL;
    int i = 0;
    int j = 0;

    int size = sizeoflinkedlist(head);
    if (k % size == 0)
    {
        return head;
    }
    else
    {  k=k%size; 
        for (int i = 0; i < k; i++)
        {
            while (p->next != NULL)
            {
                q = q->next;
                p = p->next;
            }
            q->next = NULL;
            p->next = head;
            head=p;
            q=p;
            p=p->next;
        
        }
        return head;
    }
}
    int main()
    {

        Node *first1 = new Node;
        Node *second1 = new Node;
        Node *third1 = new Node;
        Node *fourth1 = new Node;
        Node *fifth1 = new Node;

        first1->data = 1;
        first1->next = second1;

        second1->data = 2;
        second1->next = third1;

        third1->data = 3;
        third1->next = fourth1;

        fourth1->data = 2;
        fourth1->next = fifth1;

        fifth1->data = 1;
        fifth1->next = NULL;

        cout << "List 1:" << endl;
         first1 = rotate(first1,6);
        traversal(first1);
        return 0;
    }
