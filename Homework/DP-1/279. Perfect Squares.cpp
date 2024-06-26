/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
  */



class Solution {
public:
    int solve(int n,vector<int> &dp) {
      if(n==0){
          return 0;
      }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=n;
        for(int i=1;i*i<=n;i++){
            int temp=i*i;
            ans=min(ans,1+solve(n-temp,dp));
        }
        dp[n]=ans;
        return ans;
    }
    
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
