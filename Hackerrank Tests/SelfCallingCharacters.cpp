/* 
You will be given a positive integer N. Your task is to find the smallest number greater than or equal to N that is a prime and a palindrome.

Input Format

Enter the number N, only integer number can be consider as N.

Constraints

1 <= N <= 106

Output Format

Output is also in integer form.
 */

// https://www.hackerrank.com/contests/practice-test-ke020/challenges/self-calling-characters/submissions/code/1382220029

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(int n) {
    string s = to_string(n);
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

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

int findPrimePalindrome(int n) {
    int currentNumber = n;
    while (true) {
        if (isPalindrome(currentNumber) && isPrime(currentNumber)) return currentNumber;
        currentNumber++;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n; cin>>n;
    cout<<findPrimePalindrome(n);
    
    return 0;
}
