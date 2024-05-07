/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.

  */

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        int i=0;
        for(auto node:edges){
            int u=node[0];
            int v=node[1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
            i++;
        }
        
        vector<double> desti(n,INT_MIN);
        vector<bool> vis(n,false);
       queue<pair<double,int>> q;
        
        q.push({1.0,start_node});
        desti[start_node]=1.0;
        vis[start_node]=true;
        
        while(!q.empty()){
            auto node_pair=q.front();
            q.pop();
            double succ=node_pair.first;
            int nodeA=node_pair.second;
            vis[nodeA]=true;
            
            for(auto it:adj[nodeA]){
               double prob=it.second;
               int nodeB=it.first;  
                if(desti[nodeA]*prob>desti[nodeB]){
                    desti[nodeB]=desti[nodeA]*prob;
                    
                    q.push({desti[nodeB],nodeB});
                }
            }   
        }
         
        if(desti[end_node]==INT_MIN){
            return 0;
        }
        
        return desti[end_node];
        
    }
};
