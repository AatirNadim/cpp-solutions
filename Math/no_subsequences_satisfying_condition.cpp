// problem link --> https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// my solution link --> https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/discuss/3492481/C%2B%2B-oror-Short-and-Simple-oror-Math

class Solution {
public:
    typedef long long int ll;
    int mod = 1e9 + 7;
    int get_max(vector<int>& nums, int val) {
        int minval = 0, maxval = nums.size() - 1, medval;
        while(minval <= maxval) {
            medval = minval + ((maxval - minval)>>1);
            if(nums[medval] > val) maxval = medval - 1;
            else minval = medval + 1;
        }
        return maxval;
    }
    int getSub(vector<ll>& pow_2, int val) {
        return (int)pow_2[val + 1] - 1;
        ll res = 0; val++;
        res = (2<<(val)) % mod;
        return (int)res - 1;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        vector<ll> pow_2(n + 1, 1);
        for(int i=1;i<=n;i++) {
            pow_2[i] = (pow_2[i-1]%mod *2)%mod;
        }
        sort(nums.begin(), nums.end());
        for(int& i : nums) {
            if((i<<1) > target) break;
            res++;
        }
        for(int i=0;i<n;i++) {
            int right = get_max(nums, target - nums[i]);
            if(right <= i) break;
            res = (res%mod + getSub(pow_2, right - i - 1)%mod)%mod;
        }
        return res;
    }
};