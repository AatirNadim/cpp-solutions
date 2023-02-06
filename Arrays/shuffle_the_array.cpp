// problem link --> https://leetcode.com/problems/shuffle-the-array/

// my solution link --> https://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // vector<int> res((n<<1));
        vector<int> res;
        for(int i=0;i<n;i++) {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
        }
        return res;
    }
};