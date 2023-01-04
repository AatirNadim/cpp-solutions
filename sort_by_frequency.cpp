// problem link --> https://leetcode.com/problems/sort-array-by-increasing-frequency/

// my solution link --> https://leetcode.com/problems/sort-array-by-increasing-frequency/discuss/2996688/C%2B%2B-oror-Hashmap


class Solution {
public:
    void func(vector<int>& res, int ele, int val) {
        for(int i=0;i<val;i++) res.push_back(ele);
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> hash(201), res;
        int maxlen = 0;
        for(int&i : nums) {
            hash[i + 100]++;
            maxlen = max(maxlen, hash[i + 100]);   
        }
        vector<vector<int>> freq(maxlen + 1);
        for(int i=200;i>=0;i--) {
            freq[hash[i]].push_back(i - 100);
        }
        for(int i=1;i<=maxlen;i++) {
            if(freq[i].size()) {
                for(int& ele : freq[i]) func(res,ele, i);
            }
        }
        return res;
    }
};