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

void deleteKthNode(int k, Node *&head)      // not working for k=n; ex testcase: 5 1 2 3 4 5 5 
{
    Node *slow = head;
    Node* fast = head;
    int count = 0;
    while (count <= k)
    {
        fast = fast->next;
        count++;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node* temp = slow->next;
    slow -> next = slow->next->next;
    delete temp;
    return;
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
    Node *head = NULL;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtHead(val, head);
    }
    print(head);
    int k;
    cin >> k;
    deleteKthNode(k, head);
    print(head);
    return 0;
}