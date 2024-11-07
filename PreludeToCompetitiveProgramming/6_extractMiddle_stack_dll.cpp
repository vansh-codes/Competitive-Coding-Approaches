#include <bits/stdc++.h>
using namespace std;

// Method1 using stl: shift n/2 elements to another temp stack, extract middle, again shift from temp to original
// Method2 using linked lists: maintain middle pointer and counter variable to maintain count of elements, not possible for single ll, because cant move backwards when popped
// Method3 using doubly ll: maintain middle pointer
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node *top = NULL;
    Node *middle = NULL;
    Node* head = NULL;
    int count = 0;
    int choice;
    do
    {
        cout << "1. Push\n2. Pop\n3. Extract Middle\n4. Display\n5. Exit\n";
        cin >> choice;
        int val;
        Node *newNode;
        switch (choice)
        {
        case 1: //* Push in O(1)
            cout << "Enter the value: ";
            cin >> val;
            newNode = new Node(val);
            count++;
            if (top == NULL)
            {
                top = newNode;
                middle = top;
                // break;
            }
            else
            {
                newNode->next = top;
                top->prev = newNode;
                top = newNode;
                if (count % 2 != 0)
                {
                    middle = middle->prev;
                }
            }
            break;
        case 2: //* Pop in O(1)
            if (top == NULL)
            {
                middle = NULL;
                cout << "\nStack is empty\n";
            }
            else
            {
                count--;
                Node *del = top;
                cout << "Popped element is: " << del->data << "\n";
                top = top->next;
                if (top != NULL)
                {
                    top->prev = NULL;
                }
                if (count % 2 == 0 && middle != NULL)
                {
                    middle = middle->next;
                }
                delete del;
            }
            break;
        case 3:     //* Extract Middle in O(1)
            if (middle == NULL)
            {
                cout << "Stack is empty\n";
            }
            else
            {
                cout << "\nMiddle ELement is: "<<middle->data << "\n\n";
            }
            break;
        case 4:     //* Display in O(n)
            if (top == NULL)
            {
                cout << "\nStack is empty\n";
                break;
            }
            head = top;
            while (head != NULL)
            {
                cout << head->data << " ";
                head = head->next;
            }
            cout << endl;
            break;
        case 5:     //* Exit
            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nInvalid choice\n";
            break;
        }
    } while (choice != 5);

    return 0;
}

// Time complexity: O(1) for push, pop, extract middle, O(n) for display
// Space complexity: O(n) for n elements in stack
