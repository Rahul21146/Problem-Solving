/*


  Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
Example 3:


Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000


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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
       
        queue<pair<TreeNode*, pair<int, int>>>q; 
        q.push({root,{0,0}});
       
        map<int, map<int, multiset<int>>>mp; 
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode* &node = front.first;
            auto coordinate = front.second;
            auto &row = coordinate.first;
            auto &col = coordinate.second;
            mp[col][row].insert(node -> data);
            if(node -> left){
                q.push({{node -> left},{row + 1, col - 1}});
            }
            if(node -> right){
                q.push({{node -> right},{row + 1, col + 1}});
            }
        }
       
        for(auto i:mp){
            auto &colmp = i.second;
            vector<int> verticalLine;
            for(auto colmpi : colmp){
                auto &mset = colmpi.second;
                verticalLine.insert(verticalLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(verticalLine);
        }
        return ans;
    }


int main(){

    TreeNode * root;
    root=buildTree();
    vector<vector<int>> ans;
    ans= verticalTraversal(root);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
