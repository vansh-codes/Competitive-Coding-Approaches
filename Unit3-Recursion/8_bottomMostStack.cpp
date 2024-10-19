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

void fetchBottom(){
    if(isEmpty()){
        return;
    } else if(top==0){
        cout<<"Bottom most element: "<<st[top]<<"\n";
        return;
    }
    int temp = pop();
    fetchBottom();
    push(temp);
}

int main(){
    int choice,val;
    do{
        cout<<"1.Push\n2.Pop\n3.Display\n4.Fetch Bottom\n5.Exit\n";
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
                fetchBottom();
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