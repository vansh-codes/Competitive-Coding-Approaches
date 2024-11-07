#include<bits/stdc++.h>
using namespace std;


// *Using 2 stacks
/* int main(){     // TC: O(1), SC: O(N)
    stack<int> st, minSt;
    int choice, val, mini = INT_MAX;
    do{
        cout<<"1.Push\n2.Pop\n3.Display Minimum\n4.Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                cin>>val;
                st.push(val);
                mini = min(mini, val);
                minSt.push(mini);
                break;
            case 2:
                if(st.empty()){
                    cout<<"Stack is empty\n";
                    break;
                }
                st.pop();
                minSt.pop();
                break;
            case 3:
                cout<<"Minimum at this instance: "<<minSt.top()<<"\n";
                break;
            case 4:
                cout<<"Exiting..";
                break;
            default:
                cout<<"Invalid choice";
                break;
        }
    }while(choice!=4);

    return 0;
} */


// * Using 1 stack
int main(){
    stack<int>st;
    int choice, val, mini = INT_MAX;
    do{
        cout<<"1.Push\n2.Pop\n3.Display Minimum\n4.Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                cin>>val;
                if(val < mini){
                    st.push(mini);
                    mini = val;
                    st.push(mini);
                } else{
                    st.push(val);
                }
                break;
            case 2:
                if(st.empty()){
                    cout<<"Stack is empty\n";
                    break;
                }
                if(st.top() == mini){
                    st.pop();
                    mini = st.top();
                    st.pop();
                } else{
                    st.pop();
                }
                break;
            case 3:
                cout<<"Minimum at this instance: "<<st.top()<<"\n";
                break;
            case 4:
                cout<<"Exiting..";
                break;
            default:
                cout<<"Invalid choice";
                break;
        }
    }while(choice!=4);
}