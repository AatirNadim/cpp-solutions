// problem link --> https://leetcode.com/problems/k-radius-subarray-averages/

// my solution link --> https://leetcode.com/problems/k-radius-subarray-averages/discuss/3660291/C%2B%2B-oror-Math-oror-Sliding-Window-oror-Short-and-Simple

class Solution {
public:
    typedef long long int ll;
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, -1);
        if(n < 2*k + 1) return res;
        ll currsum = 0, m = 2*k + 1;
        for(int i=0;i<=2*k;i++) {
            currsum += nums[i];
        }
        res[k] = currsum/m;
        for(int i=k+1;i<n-k;i++) {
            currsum += (nums[i+k] - nums[i-k-1]);
            res[i] = currsum/m;
        }
        return res;
    }
};