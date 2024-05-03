/*
  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

  */


class Solution {
public:
    int robber(vector<int> &nums, vector<int> &dp, int index ){
    if(index>=nums.size()){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    //include
    int ans1=nums[index]+robber(nums,dp,index+2);
    int ans2= 0+robber(nums, dp, index+1);

    dp[index]= max(ans1,ans2);

    return dp[index];
}
    int rob(vector<int>& nums) {
        int index=0;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        

          
       vector<int> temp1,temp2;
        
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(i!=nums.size()-1){
                temp2.push_back(nums[i]);
            }
        }
        
        vector<int> dp1(temp1.size()+1,-1);
        vector<int> dp2(temp2.size()+1,-1);
        int ans1=robber(temp1,dp1,index);
        int ans2=robber(temp2,dp2,index);
        
        return max(ans1,ans2);
    }
};
