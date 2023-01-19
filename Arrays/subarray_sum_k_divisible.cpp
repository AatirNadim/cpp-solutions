// problem link --> https://leetcode.com/problems/subarray-sums-divisible-by-k/

// my solution link --> https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/3072717/C%2B%2B-oror-Prefix-Sum-oror-Short-and-Simple

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int currsum = 0, res = 0;
        mp[0] = 1;
        for(int &i : nums) {
            currsum += i;
            res += mp[(currsum%k + k)%k]++;
        }
        return res;
    }
};