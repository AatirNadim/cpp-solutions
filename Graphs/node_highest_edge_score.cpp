// problem link --> https://leetcode.com/problems/node-with-highest-edge-score/

// my solution link --> https://leetcode.com/problems/node-with-highest-edge-score/discuss/2996332/C%2B%2B-oror-Hashmap-oror-Short-and-Simple

#define ll long long int
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<ll> hash(n);
        ll maxval = 0; int res = n;
        for(int i=0;i<n;i++) {
            hash[edges[i]] += i;
            if(hash[edges[i]] > maxval) {
                maxval = hash[edges[i]], res = edges[i];
            }
            else if(hash[edges[i]] == maxval) res = min(res, edges[i]);
        }
        return res;
    }
};