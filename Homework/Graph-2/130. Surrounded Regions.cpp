/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.*/

class Solution {
public:
    bool isSafe(vector<vector<char>> &ans, map<pair<int,int>,bool> &vis,int row,int col){
        int n=ans.size();
        int m=ans[0].size();
        if(row >= 0 && row < n && col >= 0 && col < m && !vis[{row, col}] && ans[row][col] == 'O'){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char>>&ans, map<pair<int,int>,bool> &vis,int row,int col){
        vis[{row,col}]=true;
        ans[row][col]='P';

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
        
            for (int i = 0; i < 4; i++)
            {
                int newX = row + dx[i];
                int newY = col + dy[i];
                if(isSafe(ans,vis,newX,newY)){
                    dfs(ans,vis,newX,newY);
                }
            }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>> ans=board;
        map<pair<int,int>,bool> vis;
        
        
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if((i==0 || i==n-1 ||j==0 || j==m-1) && ans[i][j]=='O'){
                   dfs(ans,vis,i,j);
               }
           }
        }
        
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if (ans[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (ans[i][j] == 'P') {
                    board[i][j] = 'O';
                }            
           }
            
        }
        
        
        
    }
};
