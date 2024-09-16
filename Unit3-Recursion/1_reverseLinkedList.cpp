#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = NULL;
        }
        void insertAtEnd(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void reverseLinkedList(){
            Node* prev = NULL;
            Node* current = head;
            Node* next = NULL;
            while(current != NULL){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
        void reverseLinkedListRecursive(Node* prev, Node* current){
            if(current == NULL){
                head = prev;
                return;
            }
            Node* next = current->next;
            current->next = prev;
            reverseLinkedListRecursive(current, next);
        }

        void printLinkedList(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};


int main(){
    LinkedList ll;
    int n; cout<<"Enter linked list size: " ;cin>>n;
    int data; 
    for(int i=0;i<n;i++){
        cin>>data;
        ll.insertAtEnd(data);
    }
    cout<<"Original Linked List: ";
    ll.printLinkedList();

    ll.reverseLinkedList();
    cout<<"Reversed ll: ";
    ll.printLinkedList();

    cout<<"Reversed ll using recursion: ";
    ll.reverseLinkedListRecursive(NULL, ll.head);
    ll.printLinkedList();

    return 0;
}