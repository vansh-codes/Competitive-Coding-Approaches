#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int st[MAX];
int top = -1;

bool isEmpty(){
    return top==-1;
}

bool isFull(){
    return top==MAX-1;
}

void push(int val){
    if(isFull()){
        cout<<"Stack overflow\n";
        return;
    }
    top++;
    st[top] = val;
}

int pop(){
    if(isEmpty()){
        cout<<"Stack underflow\n";
        return -1;
    }
    return st[top--];
}

void display(){
    if(isEmpty()){
        cout<<"Stack is empty\n";
        return;
    }
    for(int i=top;i>=0;i--){
        cout<<st[i]<<" ";
    }
    cout<<"\n";
}

void insertSorted(int val){
    if(isEmpty() || st[top]<=val){
        push(val);
        return;
    }
    int temp = pop();
    insertSorted(val);
    push(temp);
    return;
}

void sortStack(){
    if(isEmpty()){
        return;
    }
    int temp = pop();
    sortStack();
    insertSorted(temp);
}

int main(){
    int choice,val;
    do{
        cout<<"1.Push\n2.Pop\n3.Display\n4.Sort\n5.Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                cin>>val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                sortStack();
                break;
            case 5:
                cout<<"Exiting..\n";
                break;
            default:
                cout<<"invalid choice\n";
                break;
        }
    }while(choice!=5);
}

// Expected ques:
// Delete element from middle
// Swap element of stacks
// fetch Bottom most element of the stack