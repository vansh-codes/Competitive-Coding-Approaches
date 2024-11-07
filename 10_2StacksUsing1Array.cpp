#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    //* not optimal
/*     int top1 = 0, top2 = n/2;
    int choice, val;
    do{
        cout<<"1.Push in stack1\n2.Pop in stack1\n3.Push in stack2\n4.Pop in stack2\n5.Display\n6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the value to push: ";
                cin>>val;
                if(top1<n/2){
                    arr[top1] = val;
                    top1++;
                }
                else{   
                    cout<<"Stack Overflow\n";
                }
                break;
            case 2:
                if(top1>0){
                    cout<<"Popped: "<<arr[top1-1]<<"\n";
                    top1--;
                }
                else{
                    cout<<"Stack Underflow\n";
                }
                break;
            case 3:
                cout<<"Enter the value to push: ";
                cin>>val;
                if(top2<n){
                    arr[top2] = val;
                    top2++;
                }
                else{
                    cout<<"Stack Overflow\n";
                }
                break;
            case 4:
                if(top2>n/2){
                    cout<<"Popped: "<<arr[top2-1]<<"\n";
                    top2--;
                }
                else{
                    cout<<"Stack Underflow\n";
                }
                break;
            case 5:
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<"\n";
                break;
            case 6:
                cout<<"Exiting..\n";
                break;
            default:
                cout<<"Invalid Choice\n";
                break;
        }
    }while(choice!=6); */

    int top1 = 0, top2 = n-1;
    int choice, val;
    do{
        cout<<"1.Push in stack1\n2.Pop in stack1\n3.Push in stack2\n4.Pop in stack2\n5.Display\n6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the value to push: ";
                cin>>val;
                if(top1<=top2){
                    arr[top1] = val;
                    top1++;
                }
                else{   
                    cout<<"Stack Overflow\n";
                }
                break;
            case 2:
                if(top1>0){
                    cout<<"Popped: "<<arr[top1-1]<<"\n";
                    arr[top1-1]=-1;
                    top1--;
                }
                else{
                    cout<<"Stack Underflow\n";
                }
                break;
            case 3:
                cout<<"Enter the value to push: ";
                cin>>val;
                if(top2>=top1){
                    arr[top2] = val;
                    top2--;
                }
                else{
                    cout<<"Stack Overflow\n";
                }
                break;
            case 4:
                if(top2<n-1){
                    cout<<"Popped: "<<arr[top2+1]<<"\n";
                    arr[top2+1] = -1;
                    top2++;
                }
                else{
                    cout<<"Stack Underflow\n";
                }
                break;
            case 5:
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<"\n";
                break;
            case 6:
                cout<<"Exiting..\n";
                break;
            default:
                cout<<"Invalid Choice\n";
                break;
        }
    }while(choice!=6);

    return 0;
}