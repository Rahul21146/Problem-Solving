/*


1760. Minimum Limit of Balls in a Bag



You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

 

Example 1:

Input: nums = [9], maxOperations = 2
Output: 3
Explanation: 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
Example 2:

Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.
 

Constraints:

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109







*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isPossible(vector<int> &nums, int k , int mid){
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%mid==0){
            count+=(nums[i]/mid-1);
        }
        else{
            count+=nums[i]/mid;
        }
        if(count>k){
            return false;
        }
    }
    if(count>k){
        return false;
    }
    return true;
}

int solve(vector<int>&nums, int k){
    int start=1;
    int end=0;
    int maxi=0;
    for(int i=0;i<nums.size();i++){
        maxi = max(maxi,nums[i]);
    }
    end=maxi;

    int ans=0;
    while(start<=end){
        int mid=start+(end-start)/2;

        if(isPossible(nums,k,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int> nums={431,922,158,60,192,14,788,146,788,775,772,792,68,143,376,375,877,516,595,82,56,704,160,403,713,504,67,332,26};
    int maxOperations=80;
    int ans= solve(nums,maxOperations);
   
    cout<<ans;

    return 0;
}
