#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st,val);
    st.push(temp);
    return;
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,temp);
    return;
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}

int main(){
    stack<int> st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.push(x);
    }
    printStack(st);
    reverseStack(st);
    printStack(st);

    return 0;
}