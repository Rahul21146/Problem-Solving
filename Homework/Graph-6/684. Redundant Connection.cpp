/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
  */

class Solution {
    std::vector<int> dsu;
    std::vector<int> size;
public:
    int find(int v) {
        if (dsu[v] == v) {
            return v;
        }
        return dsu[v] = find(dsu[v]);
    }

    void uni(int v1, int v2) {
        if (size[v1] < size[v2]) {
            std::swap(v1, v2);
        }
        size[v1] += size[v2];
        dsu[v2] = v1;
    }

    vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
        int n = edges.size();
        dsu = std::vector<int>(n);
        size = std::vector<int>(n, 1);
        std::iota(dsu.begin(), dsu.end(), 0);
        for (std::uint32_t i = 0; i < n; ++i) {
            int v1 = find(edges[i][0] - 1);
            int v2 = find(edges[i][1] - 1);
            if (v1 == v2) {
                return edges[i];
            } else {
                uni(v1, v2);
            }
        }
        return {0, 0};
    }
};
