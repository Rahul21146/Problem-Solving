/*

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

#include <iostream>
#include <vector>
using namespace std;

void findFirstPosition(vector<int> &nums, int target, vector<int> &ans)
{
    int s = 0, m;
    int e = nums.size() - 1;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (nums[m] == target)
        {
            ans[0] = m;
            e = m - 1;
        }
        else if (nums[m] < target)
            s = m + 1;
        else
            e = m - 1;
    }
}

void findLastPosition(vector<int> &nums, int target, vector<int> &ans)
{
    int s = 0;
    int e = nums.size() - 1;
    int m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (nums[m] == target)
        {
            ans[1] = m;
            s = m + 1;
        }
        else if (nums[m] < target)
            s = m + 1;
        else
            e = m - 1;
    }
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> ans(2, -1);
    int target = 8;
    findFirstPosition(nums, target, ans);
    findLastPosition(nums, target, ans);
    for(int i=0;i<2;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}



