// problem link --> https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

// my solution link --> https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/discuss/2996030/C%2B%2B-oror-HashMap-oror-Mod3-oror-Short-and-Simple

class Solution {
public:
    int min_curr(int val) {
        if(val == 1) return -1;
        if(val%3) return val/3 + 1;
        return val/3;
    }
    int minimumRounds(vector<int>& tasks) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int& task : tasks) mp[task]++;
        for(auto &p : mp) {
            int val = min_curr(p.second);
            if(val + 1) res += val;
            else return -1;
        }
        return res;
    }
};