
/*

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
  */

class Solution {
public:

    void solve(vector<string> &ans, string temp, TreeNode* root){
        //base case
        if(root->left==NULL && root->right==NULL){
            temp+=to_string(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp=temp+to_string(root->val);
        temp=temp+"->";

        if(root->left!=NULL){
            solve(ans, temp ,root->left);
        }
        if(root->right!=NULL){
            solve(ans, temp, root->right);
        }
        temp.pop_back();
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp;
        solve(ans,temp,root);
        return ans;
    }
};
