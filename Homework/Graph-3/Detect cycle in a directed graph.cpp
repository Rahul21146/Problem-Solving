/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105
  */


class Solution {
  public:
  
  bool chech_cycle_undirected_graph(int src,vector<int> adjlist[],unordered_map<int,bool> &visited,unordered_map<int,int> &DFS_Treck){
        visited[src]=true;
        DFS_Treck[src]=true;

        for(auto nbr: adjlist[src]){
            if(!visited[nbr]){
                if(chech_cycle_undirected_graph(nbr,adjlist,visited,DFS_Treck)){
                    return true;
                }
            }
            if(visited[nbr]==true && DFS_Treck[nbr]==true){
                return true;
            }
        }

        //backtarcking
        DFS_Treck[src]=false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        unordered_map<int,int> DFS_Treck;
        unordered_map<int,bool> visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(chech_cycle_undirected_graph(i,adj,visited,DFS_Treck)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};
