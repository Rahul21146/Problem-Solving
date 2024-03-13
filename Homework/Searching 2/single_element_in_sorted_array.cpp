/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105


*/

#include <iostream>
#include <vector>
using namespace std;

int singleElement(vector<int> & nums){
    int n=nums.size();
    int start=0;
    int end= n-1;
    int mid;
    while(start<end){
        mid= start+(end-start)/2;
        if(mid%2==0){
            if(nums[mid]==nums[mid-1]){
                end=mid-2;
            }
            else if(nums[mid]==nums[mid+1]){
                start=mid+2;
            }
            else{
                return nums[mid];
            }
        }
        else{
            if(nums[mid]==nums[mid-1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return nums[end];
    
}


int main()
{

    vector<int> nums = {1,1,2,2,3};
    int ans=singleElement(nums);
    cout<<ans;
    return 0;
}
