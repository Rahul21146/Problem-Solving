/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
  */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    bool isTrue(TreeNode* root,set<int> &s,int k){
        if(root==NULL){
            return false;
        }
        if(isTrue(root->left,s,k)){
            return true;
        }
        if(s.find( k- root->val) != s.end()){
            return true;
        }

        s.insert(root->val);
        if(isTrue(root->right, s,k)){
            return true;
        }
        return false; 
        
        
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return isTrue(root,s,k);
    }
};
