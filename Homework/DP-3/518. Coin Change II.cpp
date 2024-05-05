/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
  */

//recurrsion--------------------------------------->
class Solution {
public:
    int solve(int amount, vector<int>& coins,int index){
        if(amount==0){
            return 1;
        }
        if(amount<0 || index==coins.size()){
            return 0;
        }
        int include = solve(amount - coins[index], coins, index);
        int exclude = solve(amount, coins, index + 1);
        
        int ans=include+exclude;
        return ans;
        
    }
    int change(int amount, vector<int>& coins) {
        int index=0;
        return solve(amount,coins,index);
    }
};
//memoisation--------------------------------------------->
class Solution {
public:
    int solve(int amount, vector<int>& coins,int index,vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(amount<0 || index==coins.size()){
            return 0;
        }
        if(dp[amount][index]!=-1){
           return dp[amount][index]; 
        }
        int include = solve(amount - coins[index], coins, index,dp);
        int exclude = solve(amount, coins, index + 1,dp);
        
        dp[amount][index]=include+exclude;
        return dp[amount][index];
        
    }
    int change(int amount, vector<int>& coins) {
        int index=0;
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
        return solve(amount,coins,index,dp);
    }
};

//botttom up apporach------------------------------------------>
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int index=0;
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
            for(int j=0;j<n;j++){
                dp[0][j]=1;
            }
        
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                int include = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;
                int exclude = (j >= 1) ? dp[i][j - 1] : 0;
                dp[i][j] = include + exclude;
            }
        }
        
        return dp[amount][n-1];
    }
};
