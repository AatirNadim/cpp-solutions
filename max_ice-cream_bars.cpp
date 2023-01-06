// problem link --> https://leetcode.com/problems/maximum-ice-cream-bars/

// my solution link --> https://leetcode.com/problems/maximum-ice-cream-bars/discuss/3006650/C%2B%2B-oror-Sorting-oror-O(1)-space

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0, n = costs.size(), idx = 0;
        sort(costs.begin(), costs.end());
        while(idx < n) {
            if(costs[idx] > coins) break;
            coins -= costs[idx], res++;
            idx++;
        }
        return res;
    }
};