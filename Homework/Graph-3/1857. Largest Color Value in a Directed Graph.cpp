/*
  There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 

Example 1:



Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
Example 2:



Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.
 

Constraints:

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n
  */

class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<bool> &track, vector<vector<int>> &colorMax, string &colors, int &ans, bool &isCycle) {
        vis[node] = true;
        
        for(int k: adj[node]) {
            if (!vis[k]) {
                dfs(k, vis, adj, track, colorMax, colors, ans, isCycle);
            } else if (!track[k]) isCycle = true;
            for(int it=0;it<26;it++) {
                colorMax[node][it] = max(colorMax[node][it], colorMax[k][it]);
            }
        }
        
        colorMax[node][colors[node] - 'a'] += 1;
        ans = max(ans, colorMax[node][colors[node] - 'a']);
        track[node] = true;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<bool> track(n, false);
        vector<bool> vis(n, false);
        bool isCycle = false;
        vector<vector<int>> adj(n);
        vector<vector<int>> colorMax(n, vector<int> (26, 0));
        int ans = 1;

        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, track, colorMax, colors, ans, isCycle);
            }
        }

        if (isCycle) return -1;
        return ans;
    }
};
