// problem link --> https://leetcode.com/problems/divide-array-into-equal-pairs/

// my solution link --> https://leetcode.com/problems/divide-array-into-equal-pairs/discuss/2996729/C%2B%2B-oror-Unordered_map-oror-Short-and-Simple

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int& i : nums) mp[i]++;
        for(auto &p : mp) {
            if(p.second&1) return 0;
        }
        return 1;
    }
};