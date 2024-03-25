/*
  Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.

Example 1:

Input:
            1
          /   \
         2     3

Output: -4

Explanation:
sum at odd levels - sum at even levels
= (1)-(2+3) = 1-5 = -4

Example 2:

Input:
            10
          /    \
        20      30
       /  \         
     40    60      

Output: 60

Explanation:
sum at odd levels - sum at even levels
= (10+40+60) - (20+30)
= 110 - 50
= 60

Your Task:  
You dont need to read input or print anything. Complete the function getLevelDiff() which takes root node as input parameter and returns an integer.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^5
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


  void levelOrder(TreeNode *root,int level,int &oddsum, int &evensum){
      if(root==NULL){
          return;
      }
      if(level%2==0){
          evensum+=root->data;
      }
      if(level%2!=0){
          oddsum+=root->data;
      }
      levelOrder(root->left,level+1,oddsum,evensum);
      levelOrder(root->right,level+1,oddsum,evensum);
  }

    int getLevelDiff(TreeNode *root)
    {
       int oddsum=0;
       int evensum=0;
       int level=1;
       levelOrder(root,level,oddsum,evensum);
       
       return (oddsum-evensum);
    }


int main(){

    TreeNode * root;
    root=buildTree();
    int ans=getLevelDiff(root);
    cout<<ans;

    return 0;
}
