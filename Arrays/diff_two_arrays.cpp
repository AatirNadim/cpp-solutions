// problem link --> https://leetcode.com/problems/find-the-difference-of-two-arrays/

// my solution link --> https://leetcode.com/problems/find-the-difference-of-two-arrays/discuss/3480532/C%2B%2B-oror-HashMap-oror-Short-and-Simple

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a, b;
        unordered_map<int, bool> mp1, mp2;
        for(int& i : nums1) mp1[i] = 1;
        for(int& i : nums2) mp2[i] = 1;
        for(int& i : nums1) mp2[i] = 0;
        for(int& i : nums2) mp1[i] = 0;
        for(auto&p : mp1) {
            if(p.second) a.push_back(p.first);
        }
        for(auto&p : mp2) {
            if(p.second) b.push_back(p.first);
        }
        return {a, b};
    }
};