
/*
Given two BSTs, return elements of both BSTs in sorted form.


Example 1:

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: 
After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7.
Example 2:

Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: 
After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12.

Your Task:
You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.


Expected Time Complexity: O(M+N) where M and N are the sizes of the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + M + N(for storing the answer)).


Constraints:
1 ≤ Number of Nodes ≤ 105

*/






struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    
    void inorder(vector<int> &arr, Node *root){
        if(root==NULL){
            return;
        }
        inorder(arr,root->left);
        arr.push_back(root->data);
        inorder(arr,root->right);
    }
    
    void merge(vector<int> &arr1,vector<int> &arr2,vector<int> &ans){
        int i=0;
        int j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else{
                ans.push_back(arr2[j++]);
            }
        }
        
        while(i<arr1.size()){
            ans.push_back(arr1[i++]);
        }
        
        while(j<arr2.size()){
            ans.push_back(arr2[j++]);
        }
    }
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> arr1;
       vector<int> arr2;
       
       vector<int> ans;
       
       inorder(arr1,root1);
       inorder(arr2,root2);
       
       merge(arr1,arr2,ans);
       
       return ans;
       
    }
};
