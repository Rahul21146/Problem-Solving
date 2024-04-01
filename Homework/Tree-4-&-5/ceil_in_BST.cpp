/*
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Example 1:

Input:
      5
    /   \
   1     7
    \
     2 
      \
       3
X = 3
Output: 3
Explanation: We find 3 in BST, so ceil
of 3 is 3.
Example 2:

Input:
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
X = 6
Output: 7
Explanation: We find 7 in BST, so ceil
of 6 is 7.
Your task:
You don't need to read input or print anything. Just complete the function findCeil() to implement ceil in BST which returns the ceil of X in the given BST.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 105
1 <= Value of nodes<= 105
  */


#include <iostream>
#include<queue>
using namespace std;

class Node {
        public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
                this->data = data;
                this->left = NULL;
                this->right = NULL;
        }
};


Node* insertIntoBST(Node* root, int data) {

        if(root == NULL) {
                root = new Node(data);
                return root;
        }

       

        if(root-> data > data) {
              
                root->left = insertIntoBST(root->left, data);
        }
        else {
                
                root->right = insertIntoBST(root->right, data);
        }
        return root;
}

void takeInput(Node* &root) {
        int data;
        cin >> data;

        while(data != -1) {
                root = insertIntoBST(root, data);
                cin >> data;
        }
}


void solve(Node* root, int input, int &ans){
    if(root==NULL){
        return;
    }
    if(root->data>=input){
        ans=root->data; 
         solve(root->left,input,ans);  
    }
    else{
        solve(root->right,input, ans);
    }
}

int findCeil(Node* root, int input){
    int ans=-1;
    solve(root,input,ans);
    return ans;
}
 
int main() {
	  Node* root = NULL;
	  cout << "Enter the data for Node " << endl;
	  takeInput(root);
      cout<<"Enter the value to find the ceil"<<endl;
      int input;
      cin>>input;
      cout<<findCeil(root,input);
     return 0;
    }
