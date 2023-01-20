// problem link --> https://leetcode.com/problems/non-decreasing-subsequences/

// my solution link --> https://leetcode.com/problems/non-decreasing-subsequences/discuss/3076982/C%2B%2B-oror-Recursion-oror-Short-and-Simple

class Solution {
public:
    set<vector<int>> st;
    void func(vector<int>& nums, vector<int>& temp, int& idx, int& n) {
        if(idx == n) return;
        if(temp.size() > 1) st.insert(temp);
        for(int i = idx + 1; i < n;i++) {
            if(nums[i] >= nums[idx]) {
                temp.push_back(nums[i]);
                func(nums, temp, i, n);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            temp.push_back(nums[i]);
            func(nums, temp, i, n);
            temp.pop_back();
        }
        for(vector<int> v: st) res.push_back(v);
        return res;
    }
};