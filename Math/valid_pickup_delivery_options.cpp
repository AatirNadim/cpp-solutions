// problem link --> https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

// my solution link --> https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/4026325/C%2B%2B-oror-Mathematics-oror-Combinatorics-oror-Short-and-Simple

class Solution {
public:
    typedef long long int ll;
    ll mod = 1e9 + 7;
    int countOrders(int n) {
        if(n == 1) return 1;
        int lim = 2*n + 3;
        vector<vector<ll>> ncr(lim, vector<ll>(3));
        ncr[1][0] = 1, ncr[1][1] = 1;
        for(int i=2;i<lim;i++) {
            for(int j=0;j<=2;j++) {
                if(j) {
                    ncr[i][j] = (ncr[i-1][j]%mod + ncr[i-1][j - 1]%mod)%mod;
                } else ncr[i][j] = 1;
            }
        }
        ll prev = 1, res = 0;
        for(int i=2;i<=n;i++) {
            res = (prev%mod * ncr[2*(i - 1) + 2][2]%mod)%mod;
            prev = res;
        }
        return (int)res;
    }
};