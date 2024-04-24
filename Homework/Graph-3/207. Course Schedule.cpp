/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
  */

class Solution {
public:
    void topologicalSort(int numCourses,unordered_map<int,vector<int>> &adj,vector<int> &topsort){
        queue<int> q;
        map<int,int> indegre;
        
        //sakki degree initilize kar do
        for(auto i:adj){
            for(auto j: i.second){
                indegre[j]++;
            }
        }
        
        //0 degree wali node push kar do queue me
        for(int node=0;node<numCourses;node++){
            if(indegre[node]==0){
                q.push(node);
            }
        }
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            topsort.push_back(frontNode);
            
            for(auto i:adj[frontNode]){
                indegre[i]--;
                if(indegre[i]==0){
                    q.push(i);
                }
            }
        }
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        //creating adjecency list
        for(vector<int> i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
        }
        
        vector<int> toposort;
        topologicalSort(numCourses,adj,toposort);
        
        if(toposort.size()==numCourses){
            return true;
        }
        return false;
    }
};
