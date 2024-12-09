/*
    problem link --> https://leetcode.com/problems/special-array-ii/
*/

/*
    for every element, keep the starting index for the largest valid subarray the current index can be a part of.
    if for a query the starting index and the ending index lie in the same subarray, the query is valid
*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> hash(n);
        for(int i=1;i<n;i++) {
            if((nums[i]&1) - (nums[i - 1]&1)) hash[i] = hash[i - 1];
            else hash[i] = i;
        }
        vector<bool> res;
        for(vector<int>& query: queries) {
            res.push_back(hash[query[0]] == hash[query[1]]);
        }
        return res;
    }
};