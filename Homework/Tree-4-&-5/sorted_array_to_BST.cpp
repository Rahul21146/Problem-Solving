/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

  */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};


TreeNode* solve(int start,int end,vector<int> &nums){
    //base case
    if(start>end){
        return NULL;
    }

    int mid=start+(end-start)/2;
    TreeNode* root=new TreeNode(nums[mid]);

    root->left=solve(start,mid-1, nums);

    root->right=solve(mid+1,end,nums);

    return root;

    
}
TreeNode* createBST(vector<int> &nums){
    int start=0;
    int end=nums.size()-1;
    TreeNode* root=solve(start,end,nums);
    return root;
}


int main(){
    vector<int> nums={1,3};
    TreeNode* root=createBST(nums);
    return 0;
}
