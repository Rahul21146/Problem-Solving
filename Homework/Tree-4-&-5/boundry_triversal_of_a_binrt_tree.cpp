/*
You are given a binary tree having 'n' nodes.



The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, each node considered once.



Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.



Example :
Input: Consider the binary tree A as shown in the figure:

Output: [10, 5, 3, 7, 18, 25, 20]

Explanation: As shown in the figure

The nodes on the left boundary are [10, 5, 3]

The nodes on the right boundary are [10, 20, 25]

The leaf nodes are [3, 7, 18, 25].

Please note that nodes 3 and 25 appear in two places but are considered once.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
10 5 20 3 8 18 25 -1 -1 7 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
10 5 3 7 18 25 20
Explanation of Sample Input 1:
The nodes on the left boundary are [10, 5, 3]

The nodes on the right boundary are [10, 20, 25]

The leaf nodes are [3, 7, 18, 25].

Please note that nodes 3 and 25 appear in two places but are considered once.
Sample Input 2:
100 50 150 25 75 140 200 -1 30 70 80 -1 -1 -1 -1 -1 35 -1 -1 -1 -1 -1 -1
Sample Output 2:
100 50 25 30 35 70 80 140 200 150
Constraints:
1 <= n <= 10000

Where 'n' is the total number of nodes in the binary tree.

Time Limit: 1 sec

*/

#include<iostream>
#include<map>
#include<queue>
using namespace std;


    class Node{
        public:
        int val;
        Node* left;
        Node* right;

        Node(int val){
            this->val=val;
            left=NULL;
            right=NULL;
        }
    };

    //create Tree

    Node* createTree(){
        cout<<"Enter the data:->"<<endl;
        int val;
        cin>>val;

        if(val==-1){
            return NULL;
        }

        Node* root=new Node(val);
        cout<<"Enter the left part of the data "<<root->val<<" Node"<<endl;
        root->left=createTree();
         cout<<"Enter the right part of the data "<<root->val<<" Node"<<endl;
         root->right=createTree();

         return root;
    }

    void left_view(Node *root){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->val<<" ";

    left_view(root->left);
}

void bottom_view(Node* root){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
       cout<<root->val<<" ";
    }
    bottom_view(root->left);
    bottom_view(root->right);
}

   void right_view(Node* root){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
       return;
    }
    right_view(root->right);
    cout<<root->val<<" ";
   }

   void boundryLeverlTraversal(Node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->val<<" ";
    left_view(root->left);
    bottom_view(root);
    right_view(root->right);
   }



int main(){

    Node* root=createTree();
    boundryLeverlTraversal(root);
    return 0;
}
