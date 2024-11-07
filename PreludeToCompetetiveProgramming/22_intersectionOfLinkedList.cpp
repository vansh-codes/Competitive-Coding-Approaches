#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(int val, Node *&head)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

int findIntersection(Node *&head1, Node *&head2)
{ // this code correct but cant make intersection ll in code so try it on leetcode https://leetcode.com/problems/intersection-of-two-linked-lists/
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    while (ptr1 != ptr2)
    {
        if (ptr1 == NULL)
            ptr1 = head2;
        else
            ptr1 = ptr1->next;
        if (ptr2 == NULL)
            ptr2 = head1;
        else
            ptr2 = ptr2->next;

        if (ptr1 == ptr2)
            return ptr1->data;
    }
    return -1;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int n1, n2, val;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        insertAtHead(val, head1);
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        insertAtHead(val, head2);
    }
    cout << "LL1: ";
    print(head1);
    cout << "LL2: ";
    print(head2);

    cout << findIntersection(head1, head2) << "\n";
    return 0;
}