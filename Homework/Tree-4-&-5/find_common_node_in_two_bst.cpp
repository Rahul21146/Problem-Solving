/*
Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.

Example 1:

Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10

Example 2:

Input:
BST1:
     10
    /  \
   2   11
  /  \
 1   3
BST2:
       2
     /  \
    1    3
Output: 1 2 3
Your Task:
You don't need to read input or print anything. Your task is to complete the function findCommon() that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.

Constraints:
1 <= Number of Nodes <= 105
1 <= Node data <= 109

  */

class Solution
{
    public:
    
    bool isfound(Node* root,int val){
        if(root==NULL){
            return false;
        }
        
        if(root->data==val){
            return true;
        }
        
            if(root->data>val)
            return isfound(root->left,val);
        
        
          else
            return isfound(root->right,val);
    }
    
    void solve(Node* root1,Node* root2, vector<int> &ans){
        if(root1==NULL){
            return;
        }
        
        solve(root1->left,root2,ans);
        int val =root1->data;
        if(isfound(root2,val)){
            ans.push_back(val);
        }
        
        solve(root1->right,root2,ans);
    }
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int> ans;
     solve(root1,root2,ans);
     return ans;
    }
};
