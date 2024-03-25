/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1


*/

class Solution {
public:
    
    void print_left_view(TreeNode *root, vector<int> &ans, int level){
    if(root==NULL){
        return ;
    }

    if(level==ans.size()){
        ans.push_back(root->val);
    }

    print_left_view(root->left,ans,level+1);
    print_left_view(root->right,ans,level+1);
}
    
    
    
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        int level=0;
        print_left_view(root,ans,level);
        return ans[ans.size()-1];
    }
};
