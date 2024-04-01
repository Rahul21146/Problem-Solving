/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
*/

#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class NodeInfo{
    public:
    bool isBst;
    int maxElement;
    int minElement;
    int size;
    NodeInfo(){}
    NodeInfo(bool isBst, int maxElement, int minElement, int size){
        this->isBst=isBst;
        this->maxElement=maxElement;
        this->minElement=minElement;
        this->size=size;
    }
};

Node* createTree(){
    cout<<"Enter the Data"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    Node* root=new Node(data);
    cout<<"Enter the left part of the Node:->"<<root->data<<endl;
    root->left=createTree();
    cout<<"Enter the right part of the Node:->"<<root->data<<endl;
    root->right=createTree();

    return root;

}

void levelOrderTriversal(Node* root){
  queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }
}

NodeInfo* largestBST(Node* root){
    if(root==NULL){
        NodeInfo* node=new NodeInfo(true,INT_MIN,INT_MAX,0);
        return node;
    }

    NodeInfo* leftSubTree=largestBST(root->left);
    NodeInfo* rightSubTree=largestBST(root->right);

    NodeInfo* node=new NodeInfo();

    if(leftSubTree->isBst && rightSubTree->isBst && root->data>leftSubTree->maxElement && root->data<rightSubTree->minElement){
        node->isBst=true;
    }
    else{
        node->isBst=false;
    }


    node->minElement=min(leftSubTree->minElement,root->data);
    node->maxElement=max(rightSubTree->maxElement,root->data);


    if(node->isBst){
        node->size=leftSubTree->size+rightSubTree->size+1;
    }
    else{
        node->size=max(leftSubTree->size ,rightSubTree->size);
    }

    return node;
     
}



int largestSizeBST(Node* root){
    NodeInfo* node =largestBST(root);
    return node->size;
}

int main(){
    Node* root=NULL;
    root=createTree();
    levelOrderTriversal(root);
    int ans=largestSizeBST(root);
    cout<<endl;
    cout<<ans;
    return 0;
}
