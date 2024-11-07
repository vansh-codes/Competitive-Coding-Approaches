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

int main()
{
    Node *top = NULL;
    int choice;
    do
    {
        cout << "1. Push\n2. Pop\n3.Display\n4. Exit\n";
        cin >> choice;
        int val;
        Node *newNode;
        Node* head;
        switch(choice)
        {
            case 1:         //* Push in O(1)
                cout << "Enter the value: ";
                cin >> val;
                newNode = new Node(val);
                if(top==NULL){
                    top = newNode;
                    break;
                }
                newNode->next = top;
                top = newNode;
                break;
            case 2:         //* Pop in O(1)
                if (top == NULL)
                {
                    cout << "\nStack is empty\n";
                }
                else
                {
                    Node *del = top;
                    cout<<"Popped element is: "<<del->data<<"\n";
                    top = top->next;
                    delete del;
                }
                break;
            case 3:
                if(top==NULL){
                    cout<<"\nStack is empty\n";
                    break;
                }
                head = top;
                while(head != NULL){
                    cout<< head->data << " ";
                    head = head->next;
                }
                cout<<endl;
                break;
            case 4:
                cout<<"\nExiting...\n";
                break;
            default:
                cout<<"\nInvalid choice\n";
                break;
        }
    } while(choice != 4);

    return 0;
}