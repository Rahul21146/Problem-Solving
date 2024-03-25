/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
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

bool isSameTree(TreeNode* p , TreeNode * q){
    if(p==NULL && q==NULL){
        return true;
    }
    if(p!=NULL && q!=NULL) {
        return ((p->data==q->data) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right)));
    }
    
    return false;
}



int main(){

    TreeNode * root1;
    cout<<"Create first Tree---->"<<endl<<endl;
    root1=buildTree();

    TreeNode * root2;
    cout<<"Create second Tree---->"<<endl<<endl;
     root2=buildTree();
    bool ans=isSameTree(root1,root2);
    cout<<ans;

    return 0;
}
