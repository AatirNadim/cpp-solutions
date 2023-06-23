// problem link --> https://leetcode.com/problems/longest-arithmetic-subsequence/

// my solution link --> https://leetcode.com/problems/longest-arithmetic-subsequence/discuss/3672905/C%2B%2B-oror-DP-oror-Vector_hashmap

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = 2, n = nums.size();
        vector<vector<int>> hash(n, vector<int>(1001));
        for(int i=1;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                hash[i][nums[i] - nums[j] + 500] = max({hash[i][nums[i] - nums[j] + 500], 1 + hash[j][nums[i] - nums[j] + 500], 2});
                
                res = max(res, hash[i][nums[i] - nums[j] + 500]);
            }
        }
        return res;
    }
};