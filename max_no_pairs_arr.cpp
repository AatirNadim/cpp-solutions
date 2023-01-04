// problem link --> https://leetcode.com/problems/maximum-number-of-pairs-in-array/

// my solution link --> https://leetcode.com/problems/maximum-number-of-pairs-in-array/discuss/2997719/C%2B%2B-oror-HashMap-oror-Count-and-Say

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int& i : nums) mp[i]++;
        vector<int> res(2);
        for(auto &p : mp) {
            res[0] += (p.second>>1);
            res[1] += (p.second&1);
        }
        return res;
    }
};