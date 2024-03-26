/*

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

 

Example 1:


Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
Example 2:


Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
1 <= startValue, destValue <= n
startValue != destValue

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

string t="";

    TreeNode * leastCommonAncestor(TreeNode* root, int startValue, int destinationValue){
    if(root==NULL){
        return NULL;
    }

    if(root->val==startValue){
        return root;
    }

    if(root->val==destinationValue){
        return root;
    }
    TreeNode* left=leastCommonAncestor(root->left,startValue,destinationValue);
    TreeNode* right=leastCommonAncestor(root->right,startValue,destinationValue);
    
    if(left==NULL && right==NULL){
        return NULL;
    }

    if(left!=NULL && right==NULL){
        return left;
    }
    if(left==NULL && right!=NULL){
        return right;
    }

    return root;
}

void triversal(TreeNode* root,int destinationvalue, char ch, string& storeDir){
    if(root==NULL){
        return;
    }

    if(root->val==destinationvalue){
        if(ch!='#'){
            storeDir+=ch;
        }
            t=storeDir;
            return;
    }

    if(ch!='#'){
        storeDir+=ch;
    }

    triversal(root->left,destinationvalue,'L',storeDir);
    triversal(root->right,destinationvalue,'R',storeDir);

    storeDir.pop_back();


}

string getDirections(TreeNode* root, int startValue, int destValue) {
    TreeNode* CommonNode=leastCommonAncestor(root,startValue,destValue);
    string rightans="";
    char ch='#';
    triversal(CommonNode,destValue,ch, rightans);
    rightans=t;
    string leftans="";
    triversal(CommonNode,startValue,ch,leftans);
    leftans=t;
    for(int i=0;i<leftans.length();i++){
        leftans[i]='U';
    }
    return leftans+rightans;
    }
};
