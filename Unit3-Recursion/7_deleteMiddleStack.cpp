#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int st[MAX];
int top = -1;
// int count = 0;

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
    // count++;
    st[top] = val;
}

int pop(){
    if(isEmpty()){
        cout<<"Stack underflow\n";
        return -1;
    }
    // count--;
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

void deleteMiddleElement(int currIndex, int n){
    if(isEmpty() || currIndex==n/2){
        pop();
        return;
    }
    int temp = pop();
    deleteMiddleElement(currIndex+1,n);
    push(temp);
    return;
}

void deleteMiddle(int n){
    deleteMiddleElement(0,n);
    return;
}

int main(){
    int choice,val;
    do{
        cout<<"1.Push\n2.Pop\n3.Display\n4.Delete Middle\n5.Exit\n";
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
                deleteMiddle(top+1);
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