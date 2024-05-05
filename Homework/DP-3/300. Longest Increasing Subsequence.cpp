/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
  */

//recurrsion------------------------------------------------------------>
class Solution {
public:

int solve(vector<int> &nums , int prev ,int curr){
    //base case
    if(curr>=nums.size()){
        return 0;
    }

    int include=0;
    if(prev==-1 || nums[prev]<nums[curr]){
         include=1+solve(nums,curr,curr+1);
    }

    int exclude=solve(nums,prev,curr+1);
    int ans=max(include,exclude);

    return ans;
}

    int lengthOfLIS(vector<int>& nums) {
    int previous=-1;
    int curr=0;
    int ans=solve(nums,previous,curr);
    return ans;
    }
};
//Memoisation-------------------------------------------------------->
class Solution {
public:

int solveUsingMemo(vector<int> &nums , int prev ,int curr,vector<vector<int>> &dp){
    //base case
    if(curr>=nums.size()){
        return 0;
    }

    if(dp[prev+1][curr]!=-1){
        return dp[prev+1][curr];
    }

    int include=0;
    if(prev==-1 || nums[prev]<nums[curr]){
         include=1+solveUsingMemo(nums,curr,curr+1,dp);
    }

    int exclude=solveUsingMemo(nums,prev,curr+1,dp);
    int ans=max(include,exclude);
    dp[prev+1][curr]=ans;

    return dp[prev+1][curr];
}

    int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n+1 ,vector<int>(n+1,-1));
    int previous=-1;
    int curr=0;
    int ans=solveUsingMemo(nums,previous,curr,dp);
    return ans;
    }
};

//Tabulatation--------------------------------------------------->
class Solution {
public:
int solveUsingTablu(vector<int> &nums ){
    int n=nums.size();
    vector<vector<int>> dp(n+1 ,vector<int>(n+1,0));
    for(int curr_index=n-1;curr_index>=0;curr_index--){
        for(int prev_index=curr_index-1;prev_index>=-1;prev_index--){

            int include=0;
            if(prev_index==-1 || nums[prev_index]<nums[curr_index]){
                    include=1+dp[curr_index+1][curr_index+1];
            }

            int exclude=dp[curr_index+1][prev_index+1];
            int ans=max(include,exclude);
            dp[curr_index][prev_index+1]=ans; 
        }
    }

    return dp[0][0];
     
}

    int lengthOfLIS(vector<int>& nums) {
    int ans=solveUsingTablu(nums);
    return ans;
    }
};
