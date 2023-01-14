// problem link --> https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

// my solution link --> https://leetcode.com/problems/lexicographically-smallest-equivalent-string/discuss/3049181/C%2B%2B-oror-DSU-oror-Union-find-oror-Easy

class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        if(parent[node] + 1) return findParent(parent, parent[node]);
        return node;
    }
    void uni(vector<int>& parent, int node1, int node2) {
        if(node1 == node2) return;
        int parent1 = findParent(parent, node1), parent2 = findParent(parent, node2);
        if(parent1 < parent2) parent[parent2] = parent1;
        else if (parent2 < parent1) parent[parent1] = parent2;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26, -1);
        int n = s1.size();
        for(int i=0;i<n;i++) {
            uni(parent, s1[i] - 'a', s2[i] - 'a');
        }
        string res = "";
        for(char c : baseStr) {
            res.push_back(char(findParent(parent, c - 'a') + 'a'));
        }
        return res;
    }
};