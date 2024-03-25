/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

*/

#include<iostream>
#include<algorithm>
using namespace std;

class treeNode{
    public:

    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

};

treeNode* buildTree(){
    int data;
    cout<<"Enter the data->"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    treeNode* root=new treeNode(data);
    cout<<"Enter the left part of thr data:-> "<<data<<" node"<<endl;
    root->left= buildTree();
     cout<<"Enter the right part of thr data:-> "<<data<<" node"<<endl;
    root->right=buildTree();

    return root;
}

int maxDepth(treeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    
    int ans=max(leftDepth,rightDepth)+1;

    return ans;
}

int main(){

    treeNode * root;
    root=buildTree();
    int max=maxDepth(root);
    cout<<max;


    return 0;
}

