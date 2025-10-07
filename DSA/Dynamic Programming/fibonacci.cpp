/*
This is an example of how we can use the 1D type Dynamic Programming (DP)
problems.
Here, memorization is taking place in a dp array having same size as n,
SC - O(n) and TC - O(n)
*/

#include<bits/stdc++.h>
using namespace std;

// This takes O(n) space complexity
int computeFibonacci(int n){
    int dp[n];
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


// Enhance the space complexity to nearly O(1) from O(n) from previous scenario
#define MAX_SIZE 3
int computeFibonacciEnhancedSC(int n){
    int dp[MAX_SIZE];
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i%MAX_SIZE] = dp[(i-1)%MAX_SIZE] + dp[(i-2)%MAX_SIZE];
    }

    return dp[n%MAX_SIZE];
}

int main(){
    int n;
    cout << "\n\nInput number: ";
    cin >> n;
    cout << "Fibonacci number with O(n) SC: "<< computeFibonacci(n)<<"\n";

    cout << "Fibonacci number with O(1) SC: "<< computeFibonacciEnhancedSC(n);
    
}