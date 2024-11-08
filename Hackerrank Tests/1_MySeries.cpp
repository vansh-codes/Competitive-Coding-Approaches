/* 
Mansi is fond of solving mental ability questions. Today while solving some questions she came across a series which she was unable to solve. Help her to find the nth term of the series. n nth term 1 3 2 8 3 18 4 32 5 60 . . . 10 300

Input Format

Enter the value of n, in integer only.

Constraints

1<= n <=6000

Output Format

As per the input number n, the output number is integer number and be a part of series.
 */

//https://www.hackerrank.com/contests/practice-test-ke020/challenges
#include <cmath>
#include <cstdio> 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int find(int n){
    int countPrime = 0;
    int res=0;
    for(int i=2;countPrime<n;i++){
        if(isPrime(i)){
            res = i;
            countPrime++;
        }
    }
    return (res+1)*n;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n; cin>>n;
    if(n<1 || n>6000) return 0;
    int nthTerm = find(n);
    cout<<nthTerm<<endl;
    return 0;
}