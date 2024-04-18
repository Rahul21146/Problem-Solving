/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.*/

class Solution {
public:
        void bfs(vector<vector<char>>& isConnected,int row,int col,vector<vector<bool>> &vis,vector<pair<int,int>> &nbr){
        vis[row][col]=true;
        
        for(auto i:nbr){
            int newRow=row+i.first;
            int newCol=col+i.second;
            
            if(newCol<isConnected[0].size() && newRow<isConnected.size() && newCol>=0 && newRow>=0 && isConnected[newRow][newCol]=='1' && vis[newRow][newCol]==false ){
                bfs(isConnected,newRow,newCol,vis,nbr);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& isConnected) {
       vector<vector<bool>>vis(isConnected.size(),vector<bool>(isConnected[0].size(),false));
        int count=0;
        vector<pair<int,int>> nbr={{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(vis[i][j]==false && isConnected[i][j]=='1'){
                    count++;
                    bfs(isConnected,i,j,vis,nbr);
                }
            }
        }
        
        return count; 
    }
};
