// problem link --> https://leetcode.com/problems/longest-consecutive-sequence/

// my solution link --> https://leetcode.com/problems/longest-consecutive-sequence/discuss/3684426/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    int getVal(unordered_map<int, int>& mp, int val) {
        if(mp[val] == val) return mp[val];
        return getVal(mp, mp[val]);
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> to, from;
        int res = 0;
        for(int& i : nums) {
            if(from.count(5));
            if(to.count(i)) to[i] = getVal(to, i);
            else if(to.count(i-1)) to[i] = getVal(to, i-1);
            else to[i] = i;
            if(from.count(i)) from[i] = getVal(from, i);
            else if(from.count(i+1)) from[i] = getVal(from, i+1);
            else from[i] = i;
            from[to[i]] = max(from[to[i]], from[i]);
            to[from[i]] = min(to[from[i]], to[i]);
            res = max(res, from[i] - to[i] + 1);
        }
        return res;
    }
};