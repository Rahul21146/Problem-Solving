/*
  Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph of size V as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V+E).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ V-1
Sum of E over all testcases will not exceed 25*106



  */


class Solution
{
	public:
	
	void dfs(int src, vector<vector<int>>& adj, vector<bool> &vis, stack<int> &s){
	    vis[src] = true;
	    
        for(auto it : adj[src]) {
            if(vis[it] == false) {
                dfs(it, adj, vis, s);
            }            
        }

        s.push(src);
	}
	
	void DFS(int src, vector<vector<int>>& reverseGraph, vector<bool> &vis){
	    
	    vis[src] = false;
	    for(auto nbr : reverseGraph[src]) {
	        if(vis[nbr] == true) {
	            DFS(nbr, reverseGraph, vis);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<bool> vis(V, false);
        vector<int> topoOrder;
        stack<int> s;
        
        //find topo order
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, s);
            }
        }
        
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            topoOrder.push_back(node);
        }
        
        //reverse the edges of the graph
        vector<vector<int>> reverseGraph(V);
        for(int i = 0; i < V; i++) {
            for(auto p : adj[i]) {
                reverseGraph[p].push_back(i);
            }
        }
        
        //apply dfs on on the ordering of the topoOrder
        int ans = 0;
        for(auto i : topoOrder) {
            if(vis[i] == true) {
                DFS(i, reverseGraph, vis);
                ans++;
            }
        }
                
        return ans;
    }
};
