// problem link --> https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

// my solution link --> https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/3493680/C%2B%2B-oror-Easy-Way

class Solution {
public:
    typedef long long int ll;
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll> sum;
        left--, right--;
        for(int i=0;i<n;i++) {
            ll val = 0;
            for(int j=i;j<n;j++) {
                val += nums[j];
                sum.push_back(val);
            }
        }
        sort(sum.begin(), sum.end());
        n = sum.size();
        for(int i=1;i<n;i++) sum[i] = (sum[i]%mod + sum[i-1]%mod)%mod;
        if(left) return (int)(sum[right]%mod - sum[left - 1]%mod)%mod;
        return (int)sum[right]%mod;
    }
};