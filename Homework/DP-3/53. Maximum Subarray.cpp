/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
  */

//recurrsion-1--------------------------------------------------------->
class Solution {
public:
    void solve(int index,int prev,vector<int>& nums,int &maxi){
        if(index>=nums.size()){
            return ;
        }
        
        int include=0;
        if(prev==INT_MIN){
            include=nums[index];
            maxi=max(include,maxi);
            solve(index+1,nums[index],nums,maxi);
        }
        else{
            prev=max(prev+nums[index],nums[index]);
            maxi=max(prev,maxi);
            solve(index+1,prev,nums,maxi);
          
        }
    }
    int maxSubArray(vector<int>& nums) {
        int index=0;
        int prev=INT_MIN;
         int maxi=INT_MIN;
        solve(index,prev,nums,maxi);
        return maxi;
    }
};

//recurrsion-2-------------------------------------------------->
class Solution {
public:
    int solve(int index, int prev, vector<int>& nums) {
        if (index >= nums.size()) {
            return INT_MIN;
        }
    
        int include = (index == 0) ? nums[index] : max(prev + nums[index], nums[index]);
        
        
        return max(include,solve(index+1,include,nums));
        
    }
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int index = 0;
        int prev = INT_MIN;
        return solve(index, prev, nums);
    }
};

//bottom up  appoach----------------------------------------------->
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int maxSum = dp[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};


//space optimization------------------------------------------------------>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int prev=nums[0];
        int maxSum = prev;

        for (int i = 1; i < n; ++i) {
            prev = max(nums[i], prev + nums[i]);
            maxSum = max(maxSum, prev);
        }

        return maxSum;
    }
};

