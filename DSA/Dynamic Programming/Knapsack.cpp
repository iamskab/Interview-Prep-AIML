/*
Given n items where each item has some weight and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible. 

Note: The constraint here is we can either put an item completely into the bag or cannot put it at all [It is not possible to put a part of an item into the bag].


*/


#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> val, vector<int>wt, int W){
    // form a tabulation
    int n = val.size(); // total elements
    vector<vector<int>> dp(n+1,vector<int>(W+1));

    // the first index in dp is for number of elems
    // the second index in dp is for weight from 1 to W

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            // if num elems is zero or weight is 0, val will be 0
            if (i==0 || j==0){
                dp[i][j] = 0;
            }
            else{
                // either we can pick the current element
                int pick = 0;
                if(wt[i-1] <= j){
                    pick = val[i-1] + dp[i-1][j-wt[i-1]];
                }

                // or we are not picking the current element
                int notPick = dp[i-1][j];

                // take the max value from pick & notPick
                dp[i][j] = max(pick, notPick);
            }

        }
    }
    return dp[n][W];

}


int main() {
    vector<int> val = {1, 7, 3};
    vector<int> wt = {2, 1, 4};
    int W = 4;

    cout << "Maximum profit: "<<knapsack(val, wt, W) << "\n";
    return 0;
}