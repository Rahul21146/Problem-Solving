/*

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000

  */


#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class TreeNode{
    public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

};

TreeNode* buildTree(){
    int data;
    cout<<"Enter the data->"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    TreeNode* root=new TreeNode(data);
    cout<<"Enter the left part of thr data:-> "<<data<<" node"<<endl;
    root->left= buildTree();
     cout<<"Enter the right part of thr data:-> "<<data<<" node"<<endl;
    root->right=buildTree();

    return root;
}

int answer=0;

void pathSum_from_each_node(TreeNode* root,int target){
    if(root==NULL){
        return;
    }

    if(root->data==target){
        answer++;
    }

    pathSum_from_each_node(root->left,target-root->data);
    pathSum_from_each_node(root->right,target-root->data);
}

int pathSum(TreeNode* root,int target){
    if(root==NULL){
        return 0;
    }

    pathSum_from_each_node(root,target);
    pathSum(root->left,target);
    pathSum(root->right,target);

    return answer;

}



int main(){

    TreeNode * root;
    root=buildTree();
    int target=8;
   int ans=pathSum(root,target);
   cout<<ans;
    
    return 0;
}
