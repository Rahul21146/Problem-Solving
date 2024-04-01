/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
  */


#include <iostream>
#include<queue>
using namespace std;

class TreeNode {
        public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data) {
                this->data = data;
                this->left = NULL;
                this->right = NULL;
        }
};


TreeNode* CreateTree(){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    TreeNode* root=new TreeNode(data);
    cout<<"Enter the left part of the data "<<data<<" Node"<<endl;
    root->left=CreateTree();
    cout<<"Enter the right part of the data "<<data<<" Node"<<endl;
    root->right=CreateTree();
    return root;
}

bool solve(TreeNode* root, long long int lb, long long int ub) {
    //base case
    if(root == NULL)
        return true;
    
    if(root->data > lb && root->data < ub) {
        bool leftAns = solve(root->left, lb, root->data);
        bool rightAns = solve(root->right, root->data, ub);
        return leftAns && rightAns;
    }
    else {
        return false;
    }

}

bool isvalidBST(TreeNode* root){
        long long int lowerBound = -4294967296 ;
        long long int upperBound = 4294967296;
        bool ans  = solve(root, lowerBound, upperBound );
        return ans;
}


int main() {
	  TreeNode* root = NULL;
	  cout << "Enter the data for Node " << endl;
	  root=CreateTree();

      bool ans=isvalidBST(root);
      cout<<ans;

	
  return 0;
}
