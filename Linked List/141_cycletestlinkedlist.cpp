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
Node *intersection(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    int size1 = sizeoflinkedlist(head1);
    int size2 = sizeoflinkedlist(head2);
    int diff;
    if (size1 > size2)
    {
        diff = size1 - size2;
    }
    else if (size2 > size1)
    {
        diff = size2 - size1;
    }
    else
    {
        diff = 0;
    }
    if (diff == 0)
    {

        Node *p = head1;
        Node *q = head2;

        while (p != q)
        {
            if (p == NULL || q == NULL)
            {
                return NULL;
            }
            p = p->next;
            q = q->next;
        }
        return p;
    }
    else if (size1 > size2)
    {
        Node *p = head1;
        Node *q = head2;
        int i = 0;
        while (i != diff)
        {
            i++;
            p = p->next;
        }
        while (p != q)
        {
            if (p == NULL || q == NULL)
            {
                return NULL;
            }
            p = p->next;
            q = q->next;
        }
        return p;
    }
    else
    {
        Node *p = head1;
        Node *q = head2;
        int i = 0;
        while (i != diff)
        {
            i++;
            q = q->next;
        }
        while (p != q)
        {
            if (p == NULL || q == NULL)
            {
                return NULL;
            }
            p = p->next;
            q = q->next;
        }
        return p;
    }
}
//  ATTEMPT 1
// bool hasCycle(Node *head)
// {
//     if (head == NULL)
//     {
//         return false;
//     }
//     Node *p = head;
//     Node *q = head->next;
//     while (p->next != p)
//     {
//         if (p == NULL)
//         {
//             return false;
//         }
//         while (q != p)
//         {
//             if (q == NULL)
//             {
//                 return false;
//             }
//             q = q->next;
//         }
//         if (q == p)
//         {
//             return true;
//         }
//         p = p->next;
//     }
//     return false;
//  }
// ATTEMPT 2
// bool hasCycle(Node *head)
// {
//     if (head == NULL)
//     {
//         return false;
//     }
//     Node *p = head;
//     Node *q = head->next;
//     while (1) 
//     {
//         if (p == NULL)
//         {
//             return false;
//         }
//         while (1)
//         {
//             if (q == NULL)
//             {
//                 return false;
//             }
          
//             if(q!=p){
//                 break;
//             }
//             if (q == p)
//             {
//                 return true;
//             }
//               q = q->next;
//         }

//         p = p->next;
//     }
//     return false;
// }


//FLOYD'S ALGORITHM
bool hasCycle(Node*head){
    Node *p=head;
    Node *q=head;
    while(q!=NULL && q->next!=NULL){
        if(p==q){
            return true;
        }
        q=q->next->next;
        p=p->next;


    }
    return false;
}

int main()
{
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node;
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 5;

    // Create cycle:
    // 5 -> 3
    fourth->next = second;

    if (hasCycle(head))
    {
        cout << "Cycle Found";
    }
    else
    {
        cout << "No Cycle";
    }

    return 0;
}