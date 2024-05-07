/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        int maxi=INT_MIN;
        vector<int> desti(n+1,INT_MAX);
        desti[k]=0;
        queue<pair<int,int>> q;
        q.push({k,-1});
        while(!q.empty()){
            auto node_pair=q.front();
            q.pop();
            int nodeU=node_pair.first;
            int timeU=node_pair.second;
            
            for(auto it: adj[nodeU]){
                int nodeV=it.first;
                int timeV=it.second;     
                
                if(desti[nodeU]+timeV<desti[nodeV]){
                    desti[nodeV]=desti[nodeU]+timeV;
                    q.push({nodeV,desti[nodeV]});
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            if(desti[i]==INT_MAX){
              return -1;  
            } 
            else{
                 maxi=max(maxi,desti[i]);
            }
        }
        return maxi;
    }
};
