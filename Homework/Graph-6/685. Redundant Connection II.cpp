/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
  */

class Solution
{
public:
    vector<int> parent, sz;

    int find_set(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    bool make_union(int x, int y){
        int a = find_set(x);
        int b = find_set(y);
        if(a == b) return true;
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i = 0; i<n+1; i++){
            parent[i] = i;
            sz[i] = 1;
        }

        vector<int> indeg(n+1, -1);
        int b1 = -1, b2 = -1;
        for(int i = 0; i<edges.size(); i++){
            if(indeg[edges[i][1]] == -1){
                indeg[edges[i][1]] = i;
            }
            else{
                b1 = i;
                b2 = indeg[edges[i][1]]; 
                break;
            }
        }

        for(int i = 0; i<edges.size(); i++){
            if(i == b1) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            if(make_union(u, v)){
                if(b1 == -1) return {u, v};
                else return {edges[b2][0], edges[b2][1]};
            }
        }
        return {edges[b1][0], edges[b1][1]};
    }
};
