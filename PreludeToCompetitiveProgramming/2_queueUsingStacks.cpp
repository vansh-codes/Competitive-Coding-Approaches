#include <bits/stdc++.h>
using namespace std;

stack<int> st1;
stack<int> st2;

// to perform enqueue operation on queue
void enqueue(int val){
    cout << "Enqueue\n";
}

// to perform dequeue operation on queue
void dequeue(){
    cout << "Dequeue\n";
}

int main(){
    int choice;
    int val;
    do{
        cout << "Enter choice ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter val: ";
            cin >> val;
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            cout << "EXITING\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 3);

    return 0;
}