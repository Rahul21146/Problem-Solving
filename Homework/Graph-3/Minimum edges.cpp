/*
Given a directed graph with N nodes and M edges. A source node and a destination node are also given, we need to find how many edges we need to reverse in order to make at least 1 path from the source node to the destination node.
Note: In case there is no way then return -1.

Example 1:

Input:
N=3
M=2
edges[][]={{1,2},{3,2}}
src=1
dst=3
Output:
1
Explanation:
Reverse the edge 3->2.
Example 2:

Input:
N=4
M=3
edges[][]={{1,2},{2,3},{3,4}}
src=1
dst=4
Output:
0
Explanation;
One path already exists between 1 to 4 it is 1->2->3->4.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumEdgeReversal() which takes the edge list edges, N the number of nodes of the graph. src (source), and dst (destination) vertex as input parameters and returns the minimum number of edges to be reversed

Expected Time Complexity: O(M*log(M))
Expected Auxiliary Space: O(N+M)

Constraints:
1 <= N ,M<= 105
1<=edges[i][0],edges[i][1]<=N
  */

//{ Driver Code Starts
//Initial Template for C++



class Solution{
public:
    int minimumEdgeReversal(vector<vector<int>>& edges, int n, int src, int dst) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 0}); 
            adj[v].push_back({u, 1}); 
        }
        
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> s;
        

        s.insert({0, src});
        dist[src] = 0;
        
        // Dijkstra's algorithm 
        while (!s.empty()) {
            auto topElement = s.begin();
            int topDist = topElement->first;
            int topNode = topElement->second;
            s.erase(topElement);
            
            for (auto& nbrPair : adj[topNode]) {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                
                if (topDist + nbrDist < dist[nbrNode]) {
                    auto pairSourceEntry = s.find({dist[nbrNode], nbrNode});
                    if (pairSourceEntry != s.end()) {
                        s.erase(pairSourceEntry);
                    }
                    dist[nbrNode] = topDist + nbrDist;
                    s.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        
        if (dist[dst] != INT_MAX) {
            return dist[dst];
        }
        
        return -1; // If destination is unreachable
    }
};


