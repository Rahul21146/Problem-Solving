/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

Return the length of the shortest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.

 

Example 1:


Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
Output: 3
Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 
Example 2:


Input: n = 4, edges = [[0,1],[0,2]]
Output: -1
Explanation: There are no cycles in this graph.
 

Constraints:

2 <= n <= 1000
1 <= edges.length <= 1000
edges[i].length == 2
0 <= ui, vi < n
ui != vi
There are no repeated edges.
  */
class Solution {
public:
    void bfs(int src,int &mini,unordered_map<int,vector<int>> &adj,int n,bool &cycle){
        vector<bool> vis(n,false);
        vector<int> parent(n,-1);
        set<pair<int,int>> st;
        vector<int> distance(n,INT_MAX);
        vis[src]=true;
        parent[src]=-1;
        distance[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto topElement=st.begin();
            pair<int,int> topPair=*topElement;
            int dist=topPair.first;
            int node=topPair.second;
            
            st.erase(st.begin());
            
            for(auto nbr:adj[node]){
                if(vis[nbr]==true && nbr!=parent[node]){
                    cycle=true;
                    mini=min(distance[nbr]+distance[node]+1,mini);
                    
                }
                if(dist+1<distance[nbr]){
                    auto previousEntry=st.find({distance[nbr],nbr});
                    if(previousEntry!=st.end()){
                        st.erase(previousEntry);
                    }
                    
                    distance[nbr]=dist+1;
                    st.insert({distance[nbr],nbr});
                    vis[nbr]=true;
                    parent[nbr]=node;
                }
            }
            
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int mini=INT_MAX;
        unordered_map<int,vector<int>> adj;
        for(auto itr:edges){
            int u=itr[0];
            int v=itr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        bool cycle =false;
        
        for(int i=0;i<n;i++){
           //if(!vis[i])
            bfs(i,mini,adj,n,cycle);
        }
        
        if(cycle==false){
            return -1;
        }
        return mini;
    }
};
