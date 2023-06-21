// problem link --> https://leetcode.com/problems/minimum-cost-to-make-array-equal/

// my solution link --> https://leetcode.com/problems/minimum-cost-to-make-array-equal/discuss/3664628/C%2B%2B-oror-Sorting-oror-Prefix-Sum-oror-Short-and-Simple


class Solution {
public:
    typedef pair<int, int> pi;
    typedef long long int ll;
    static bool compt(pi& a, pi& b) {
        return a.first < b.first;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pi> v;
        int n = nums.size(); ll res = -1;
        for(int i=0;i<n;i++) v.push_back({nums[i], cost[i]});
        sort(v.begin(), v.end(), compt);
        vector<ll> inc, dec;
        ll currsum = v[0].second;
        inc.push_back(0); dec.push_back(0);
        for(int i=1;i<n;i++) {
            ll back = inc.back();
            inc.push_back((ll)(v[i].first - v[i-1].first)*currsum + back);
            currsum += v[i].second;
        }
        currsum = v[n-1].second;
        for(int i=n-2;i>=0;i--) {
            ll back = dec.back();
            dec.push_back((ll)(v[i+1].first - v[i].first)*currsum + back);
            currsum += v[i].second;
        }
        res = inc[0] + dec[n-1];
        for(int i=1;i<n;i++) {
            res = min(res, inc[i]+ dec[n - i - 1]);
        }
        return res;
    }
};