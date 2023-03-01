// problem link --> https://leetcode.com/problems/sort-an-array/

// my solution link --> https://leetcode.com/problems/sort-an-array/discuss/3244280/C%2B%2B-oror-Radix-Sort-oror-Short-and-Simple

class Solution {
public:
    void sort(vector<int>& v, int idx) {
        vector<vector<int>> hash(10);
        int val1 = pow(10, idx + 1), val2 = val1/10;
        for(int& i: v) {
            hash[abs((i%val1)/val2)].push_back(i);
        }
        v.clear();
        for(auto &i : hash) {
            for(auto &j : i) v.push_back(j);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int maxlen = 0, n = nums.size();
        for(int i : nums) {
            int currlen = 0;
            while(i) {
                currlen++, i/=10;
            }
            maxlen = max(maxlen, currlen);
        }
        for(int i=0;i<maxlen;i++) sort(nums, i);
        vector<int> res;
        for(int i = n-1;i>=0;i--) {
            if(nums[i] < 0) res.push_back(nums[i]);
        }
        for(int& i : nums) {
            if(i >= 0) res.push_back(i);
        }
        return res;
    }
};