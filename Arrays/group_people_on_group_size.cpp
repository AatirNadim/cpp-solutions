// problem link --> https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

// my solution link --> https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/discuss/3977107/C%2B%2B-oror-HashMap-oror-Short-and-SImple

class Solution {
public:
    vector<vector<int>> res;
    void func(int size, vector<int> v) {
        int n = v.size(), idx = 0;
        vector<int> temp;
        while(idx < n) {
            int s = size;
            temp.clear();
            while(s--) temp.push_back(v[idx++]);
            res.push_back(temp);
        }
    }
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        int n = groupSizes.size();
        for(int i=0;i<n;i++) mp[groupSizes[i]].push_back(i);
        for(auto& p : mp) {
            func(p.first, p.second);
        }
        return res;
    }
};