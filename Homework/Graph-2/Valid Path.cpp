/*
There is a rectangle with the left top as (0, 0) and the right bottom as (x, y). There are N circles such that their centers are inside the rectangle. The radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note :
We can move from any cell to any of its 8 adjacent neighbors and we cannot move outside the boundary of the rectangle at any point of time.
A circle doesn't touch a cell (i,j) if the distance from its center to the cell (i,j) is less than R.


Problem Constraints
0 <= x, y, R <= 100
1 <= N <= 1000
The Center of each circle would lie within the grid


Input Format
1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, the number of circles.
4th argument given is an Integer R, the radius of each circle.
5th argument given is an Array A of size N, where A[i] = x coordinate of the ith circle
6th argument given is an Array B of size N, where B[i] = y coordinate of the ith circle


Output Format
Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).


Example Input
x = 2
y = 3
N = 1
R = 1
A = [2]
B = [3]


Example Output
NO


Example Explanation
There is NO valid path in this case


*/

string dfs(int srcx, int srcy, int destx, int desty,vector<vector<int>>&vis){
    vis[srcx][srcy]=1;
    if (srcx == destx && srcy == desty)
     return "YES";

    int delrow[8] = {-1,-1,-1,0,1,1,1,0};
    int delcol[8] = {-1,0,1,1,1,0,-1,-1};
   
    for (int i = 0; i<8; i++){
        int xnew = srcx + delrow[i];
        int ynew = srcy + delcol[i];
       
        if (xnew >= 0 && xnew <=destx && ynew >=0 && ynew <=desty  && vis[xnew][ynew] == 0){
            if (dfs(xnew,ynew, destx, desty, vis) == "YES") return "YES";
        }
    }
    return "NO";
}

string Solution::solve(int x, int y, int n, int r, vector<int> &E, vector<int> &F) {
    vector<vector<int>>vis(x+1,vector<int>(y+1,0));

    for (int i = 0; i <=x; i++){
        int x1 = i;
        for (int j = 0; j<=y; j++){
            int y1 = j;
            for (int k = 0; k< E.size(); k++){
                int xcentre = E[k];
                int ycentre = F[k];
                if ((x1 - xcentre)*(x1-xcentre) + (y1 - ycentre)*(y1-ycentre) <= r*r){
                    vis[x1][y1]=-1;
                }
            }
        }
    }

    if (vis[x][y] == -1)
     return "NO";

    return dfs(0,0,x,y,vis);
}
