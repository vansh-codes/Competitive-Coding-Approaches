/* 
Tusharika went to a stationery shop with an amount of N in her hand. There are 4 types of pens, each of which cost Rs 1, Rs 2, Rs 5, Rs 10. Tusharika wants to buy a minimum number of pens, as she has limited space in his pocket but, at the same time she wants to spend all his money. The task is to find the minimum number of pens tusharika will buy.

Note: Shop has an infinite number of pens of each type

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integers N.

Constraints

1 <= T <= 10^5 1 <= N <= 10^9

Output Format

For each test case, print the answer
 */

//https://www.hackerrank.com/contests/practice-test-ke020/challenges
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findMinimum(int n){
    int pens = 0;
    
    pens += n/10;
    n %=10;
    // cout<<"10\n";
    if(n==0) return pens;
    
    pens += n/5;
    n %=5;
    // cout<<"5\n";
    if(n==0) return pens;
    
    pens += n/2;
    n %=2;
    // cout<<"2\n";
    if(n==0) return pens;
    
    pens += n;
    
    return pens;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        cout<<findMinimum(n)<<"\n";
    }
    return 0;
}
