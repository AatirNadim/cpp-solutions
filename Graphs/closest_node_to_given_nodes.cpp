// problem link --> https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

// my solution link --> https://leetcode.com/problems/find-closest-node-to-given-two-nodes/discuss/3097012/C%2B%2B-oror-Short-and-Simple-oror-DFS-oror-Hashvector

class Solution {
public:
    void populate(vector<int>& edges, vector<int>& hash, int node) {
        int dist = 1;
        hash[node] = 0;
        node = edges[node];
        while(node + 1) {
            if(hash[node] + 1) return;
            hash[node] = dist++;
            node = edges[node];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), res = -1, resval = 2*n;
        vector<int> hash1(n, -1), hash2(n, -1);
        populate(edges, hash1, node1);
        populate(edges, hash2, node2);
        for(int i=0;i<n;i++) {
            if(hash1[i] + 1 and hash2[i] + 1 and resval > max(hash1[i], hash2[i])) {
                resval = max(hash1[i], hash2[i]);
                res = i;
            }
        }
        return res;
    }
};