#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-linked-list/

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

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool checkPalindrome(Node* &head, Node *right)
    {
        if (right == NULL)
        {
            return true;
        }
        bool isPalin = checkPalindrome(head, right->next) && (head->data == right->data);
        head = head->next;
        return isPalin;
    }

    bool isPalindromeLL(Node *head)
    {
        if(head==NULL || head->next==NULL){
            return true;
        }
        Node* start = head;
        return checkPalindrome(start, head);
    }

    void printLinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ll;
    int n;
    cout << "Enter linked list size: ";
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        ll.insertAtEnd(data);
    }
    cout << "Original Linked List: ";
    ll.printLinkedList();

    cout << "Is the LL palindrome? ";
    cout<<ll.isPalindromeLL(ll.head)<<"\n";

    return 0;
}