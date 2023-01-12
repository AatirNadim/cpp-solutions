// problem link --> https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

// my solution link --> https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/discuss/3040016/C%2B%2B-oror-100-faster-oror-Short-and-Simple

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> hash(n), res;
        for(vector<int>& edge : edges) 
            hash[edge[1]]++;
        for(int i=0;i<n;i++) {
            if(!hash[i]) res.push_back(i);
        }
        return res;
    }
};