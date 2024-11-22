#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> ropes(n);
    for(int i=0;i<n;i++) cin>>ropes[i];

    // brute force -> doesnt works right for all cases
    /* sort(ropes.begin(), ropes.end());   // 2 3 4 7 9   -> 2 5 9 16 25 -> Cost: 5+9+16+25 = 55
    int cost = 0;
    for(int i=1;i<n;i++){
        ropes[i] += ropes[i-1];
        cost += ropes[i];
    }

    cout<<"Minimum cost to connect all ropes = "<<cost; */
    
    // Priority Queue
    priority_queue<int, vector<int>, greater<int>> pq;  // ascending order
    for(int i=0;i<n;i++) pq.push(ropes[i]); 

    int cost = 0;
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        cost += first + second;
        pq.push(first + second);
    }

    cout<<"Minimum cost to connect all ropes = "<<cost;



    // 4 2 7 6 9 
    // 2 4 6 7 9 -> 2 6 12 19 28 -> Cost: 6+12+19+28 = 65

    return 0;
}