/*

Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum distance between them. The given two nodes are guaranteed to be in the binary tree and all node values are unique.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 
2
Explanation: 
We need the distance between 2 and 3. Being at node 2, we need to take two steps ahead in order to reach node 3. The path followed will be: 2 -> 1 -> 3. Hence, the result is 2. 
Example 2:

Input:
        11
      /   \
     22  33
    /  \  /  \
  44 55 66 77
a = 77, b = 22
Output: 
3
Explanation: 
We need the distance between 77 and 22. Being at node 77, we need to take three steps ahead in order to reach node 22. The path followed will be: 77 -> 33 -> 11 -> 22. Hence, the result is 3.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
2 <= n <= 105
0 <= Data of a node <= 109
  */





class Solution{
    public:
    string t="";
    
    Node * leastCommonAncestor(Node* root, int startValue, int destinationValue){
    if(root==NULL){
        return NULL;
    }

    if(root->data==startValue){
        return root;
    }

    if(root->data==destinationValue){
        return root;
    }

    Node* left=leastCommonAncestor(root->left,startValue,destinationValue);
    Node* right=leastCommonAncestor(root->right,startValue,destinationValue);
    
    if(left==NULL && right==NULL){
        return NULL;
    }

    if(left!=NULL && right==NULL){
        return left;
    }
    if(left==NULL & right!=NULL){
        return right;
    }

    else{
        return root;
    }

    return root;
}
    
    
    
    
    
    void triversal(Node* root,int destinationvalue, char ch, string& storeDir){
    if(root==NULL){
        return;
    }

    if(root->data==destinationvalue){
        if(ch!='#'){
            storeDir+=ch;
            t=storeDir;
            return;
        }
    }

    if(ch!='#'){
        storeDir+=ch;
    }
    triversal(root->left,destinationvalue,'L',storeDir);
    triversal(root->right,destinationvalue,'R',storeDir);

    storeDir.pop_back();


}
    
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code her
        Node* CommonNode=leastCommonAncestor(root,a,b);
        string rightans="";
        char ch='#';
        triversal(CommonNode,b,ch, rightans);
        rightans=t;
        t.clear();
        string leftans="";
        triversal(CommonNode,a,ch,leftans);
        leftans=t;
        
        string s=leftans+rightans;
        return s.length();

    }
};
