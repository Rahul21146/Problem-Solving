/*
  Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
 

Constraints:

The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104

  */



#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
int result;
class infoNode{
    public:
    bool isBST;
    int sum;
    int maxElement;
    int minElement;

    infoNode(){}

    infoNode(bool isBST, int sum, int maxElement ,int minElement){
        this->isBST=isBST;
        this->sum=sum;
        this->maxElement=maxElement;
        this->minElement=minElement;
    }
    
};

TreeNode* createTree(){
    cout<<"Enter the Data"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    TreeNode* root=new TreeNode(data);
    cout<<"Enter the left part of the Node:->"<<root->val<<endl;
    root->left=createTree();
    cout<<"Enter the right part of the Node:->"<<root->val<<endl;
    root->right=createTree();

    return root;

}

void levelOrderTriversal(TreeNode* root){
  queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp=q.front();
        cout<<temp->val<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }
}

infoNode* solve(TreeNode* root){
    //base case
    if(root==NULL){
        infoNode* node=new infoNode(true,0,INT_MIN,INT_MAX);
        return node;
    }

    infoNode* leftSubTree=solve(root->left);
    infoNode* rightSubTree=solve(root->right);

    infoNode* node=new infoNode();

    if((leftSubTree->isBST==true && rightSubTree->isBST==true) && (leftSubTree->maxElement<root->val && rightSubTree->minElement>root->val)){
        node->isBST=true;
        node->sum = leftSubTree->sum + rightSubTree->sum + root->val;
        result=max(result,node->sum);
        node->maxElement=max(root->val ,max(leftSubTree->maxElement,rightSubTree->maxElement));
        node->minElement=min(root->val , min(rightSubTree->minElement,leftSubTree->minElement));
    }

    else{
        node->isBST=false;
        node->sum=max(leftSubTree->sum ,rightSubTree->sum);
        result=max(result,node->sum);
    }

    return node;

}




int largestSumBST(TreeNode* root){
    result=0;
    infoNode* node =solve(root);
    return result;
}

int main(){
    TreeNode* root=NULL;
    root=createTree();
    levelOrderTriversal(root);
    int ans=largestSumBST(root);
    cout<<endl;
    cout<<ans;
    return 0;
}
