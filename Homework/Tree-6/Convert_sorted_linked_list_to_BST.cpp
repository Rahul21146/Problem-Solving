/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
  */

class Solution {
public:
    
    bool solve(TreeNode* root, long long int lb, long long int ub) {
    //base case
    if(root == NULL)
        return true;
    
    if(root->val > lb && root->val < ub) {
        bool leftAns = solve(root->left, lb, root->val);
        bool rightAns = solve(root->right, root->val, ub);
        return leftAns && rightAns;
    }
    else {
        return false;
    }

}
    
    bool isValidBST(TreeNode* root) {
        long long int lowerBound = -4294967296 ; 
        long long int upperBound = 4294967296;
        bool ans  = solve(root, lowerBound, upperBound );
        return ans;
    }
};
