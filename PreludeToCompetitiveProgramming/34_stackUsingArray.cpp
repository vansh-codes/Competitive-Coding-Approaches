#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int top = -1;
int st[MAX];

bool isFull()
{
    return top == MAX - 1;
}

bool isEmpty()
{
    return top == -1;
}

void push(int element)
{
    if (isFull())
    {
        cout << "Stack Overflow\n";
        return;
    }
    else
    {
        st[++top] = element;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow\n";
        return;
    }
    top--;
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++)
    {
        cout << st[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int choice, element;
    while (true)
    {
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> element;
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}