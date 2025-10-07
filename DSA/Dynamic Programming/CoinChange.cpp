/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

---------------------------------------------------------------------------
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0

Leetcode problem link: https://leetcode.com/problems/coin-change/description/
*/

#include<bits/stdc++.h> 
using namespace std;


int coinsChange(vector<int> coins, int sum){

    if(sum == 0)
        return 0;

    int n = coins.size(); // total coins
    vector<int> dp(sum+1,sum+1); // each index stores minimum coins needed to reach sum i
    dp[0] = 0; // as to reach sum 0, 0 coins required

    for(int i=1; i<=sum; i++){ // iterate through each sum from 1 to sum
        for(int j=0; j<n; j++){ // iterate through each coin

            if(coins[j] <= i)
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
        }
    }

    return (dp[sum]==sum+1 ? -1 : dp[sum]);
}

int main(){
    vector<int> coins{1, 2, 3}; // 2+3 3+1+1 1+1+1+1+1 2+1+1+1 2+2+1
    int sum = 5;
    cout << "Minimum coins to reach sum is = "<<coinsChange(coins, sum)<<"\n";
}