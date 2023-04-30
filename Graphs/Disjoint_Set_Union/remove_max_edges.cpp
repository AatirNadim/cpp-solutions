// problem link --> https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

// my solution link --> https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/discuss/3470961/C%2B%2B-oror-Union-Find-oror-Keep-edges

class Solution {
public:
    int univ_edges = 0, total_edges = 0;
    int find_parent(vector<int>& parent, int i) {
        if(parent[i] + 1) return find_parent(parent, parent[i]);
        return i;
    }
    int func(vector<vector<int>>& edges, int mode, vector<int>& parent, vector<int>& rank, int& n) {
        int res = 0;
        for(vector<int>& edge: edges) {
            if(edge[0] == mode) {
                total_edges++;
                int u = edge[1], v= edge[2];
                int p1 = find_parent(parent, u), p2 = find_parent(parent, v);
                if(p1 - p2) {
                    res++;
                    if(rank[u] > rank[v]) {
                        parent[p2] = p1;
                        rank[u]++;
                    }
                    else {
                        parent[p1] = p2;
                        rank[v]++;
                    }
                }
            }
        }
        if(mode == 3) return res;
        return (res + univ_edges == n-1) ? res : -1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parent(n + 1, -1), rank(n + 1), parent1, rank1;
        univ_edges = func(edges, 3, parent, rank, n);
        int a = 0, b = 0;
        parent1 = parent, rank1 = rank;
        a = func(edges, 1, parent1, rank1, n); 
        if(a == -1) return -1;
        parent1 = parent, rank1 = rank;
        b = func(edges, 2, parent1, rank1, n);
        if(b + 1) return total_edges - a - b - univ_edges;
        return -1;
    }
};