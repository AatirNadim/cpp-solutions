// problem link --> https://leetcode.com/problems/similar-string-groups/

// my solution link --> https://leetcode.com/problems/similar-string-groups/discuss/3462851/C%2B%2B-oror-DSU-oror-Short-and-Simple


class Solution {
public:
    int findparent(vector<int>& parent, int i) {
        if(parent[i] + 1) return findparent(parent, parent[i]);
        return i;
    }
    bool equal(string& a, string& b) {
        int n = a.size(), res = 0;
        for(int i=0;i<n;i++) {
            res += (a[i] == b[i]);
        }
        return res >= n-2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), res = 0;
        vector<int> parent(n, -1), rank(n, 0);
        unordered_map<int, bool> mp;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(equal(strs[i], strs[j])) {
                    int p1 = findparent(parent, i), p2 = findparent(parent, j);
                    if(p1 == p2) continue;
                    if(p1 - p2) {
                        if(rank[i] > rank[j]) {
                            parent[p2] = p1;
                            rank[i]++;
                        }
                        else {
                            parent[p1] = p2;
                            rank[j]++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(parent[i] == -1) res++;
            
        }
        return res;
        
    }
};