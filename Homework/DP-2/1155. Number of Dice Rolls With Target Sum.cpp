/*
  You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
 

Constraints:

1 <= n, k <= 30
1 <= target <= 1000
  */

//memoisation

class Solution {
public:
    int mod=10e9;
    int solve(int n, int k, int target,vector<vector<int>> &dp){
        //base case
        if (target < 0) {
            return 0;
        }
        if(target!=0 && n==0){
            return 0;
        }
        if(n!=0 && target==0){
            return 0;
        }
        
        if(target==0 && n==0){
            return 1;
        }
        if(dp[n][target]!=-1){
           return dp[n][target]; 
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+solve(n-1,k,target-i,dp))%1000000007;;
        }
        dp[n][target]=ans;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);

        
    }
};


//bottom up apporach
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        //botto up apporach
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = 0;
                for (int x = 1; x <= k && x <= j; ++x){
                    dp[i][j] += dp[i - 1][j - x];
                    dp[i][j] %= 1000000007;
                }
            }
        }
        return dp[n][target];
        
    }
};
