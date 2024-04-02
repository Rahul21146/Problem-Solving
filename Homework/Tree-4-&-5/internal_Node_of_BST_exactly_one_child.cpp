/*
Given Preorder traversal of a BST, check if each non-leaf node has only one child. Assume that the BST contains unique entries.

Examples :

Input: pre[] = {20, 10, 11, 13, 12}
Output: Yes
The given array represents following BST. In the following BST, every internal
node has exactly 1 child. Therefore, the output is true.
        20
       /
      10
       \
        11
          \
           13
           /
         12

*/

#include<iostream>
#include<vector>
using namespace std;


bool hasOnlyOneChild(vector<int> &pre){
    int currDiff;
    int lastDiff;
    for(int i=0;i<pre.size()-1;i++){
        currDiff=pre[i]-pre[i+1];
        lastDiff=pre[i]-pre[pre.size()-1];
        if(currDiff*lastDiff<0){
            return false;
        }
    }
    return true;
}


int main(){
    vector<int> pre={8, 3, 5, 7, 6};
    if(hasOnlyOneChild(pre)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
