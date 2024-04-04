/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.
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

    int less(vector<int>& preorder,int start,int end){
        int val=preorder[start];
        int count=0;
        for(int i=start+1;i<=end;i++){
            if(preorder[i]<val){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }

    TreeNode* BulidTree(vector<int>& preorder,int start,int end){
        if(start>end){
            return NULL;
        }

        else{
           TreeNode* root=new TreeNode(preorder[start]);
        
            
            int i=less(preorder,start,end);

            root->left=BulidTree(preorder, start+1,start+i);

            root->right=BulidTree(preorder,start+i+1,end);

            return root;

        }

    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root;
        int start=0;
        int end=preorder.size()-1;
        root=BulidTree(preorder,start,end);
        return root;
    }
};
