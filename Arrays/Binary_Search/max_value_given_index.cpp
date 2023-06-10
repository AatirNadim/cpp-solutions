// problem link --> https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

// my solution link --> https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/discuss/3622728/C%2B%2B-oror-100-faster-oror-Short-and-Simple

class Solution {
public:
    typedef long long int ll;
    ll getSum(int n, int curridx, int currval) {
        currval--;
        ll one_side = (ll)currval*(currval + 1)/2;
        ll off1 = max(currval + curridx - n, 0);
        ll off2 = max(currval - curridx - 1, 0);
        return n + 2*one_side - currval - off1*(off1 + 1)/2 - off2*(off2 + 1)/2;
    }
    int maxValue(int n, int index, int maxSum) {
        int minval = 1, maxval = maxSum, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            ll currsum = getSum(n, index, medval);
            if(currsum <= maxSum) minval = medval + 1;
            else maxval = medval - 1;
        }
        return maxval;
    }
};