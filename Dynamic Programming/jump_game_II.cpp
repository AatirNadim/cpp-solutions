// problem link --> https://leetcode.com/problems/jump-game-ii/

// my solution link --> https://leetcode.com/problems/jump-game-ii/discuss/3161192/C%2B%2B-oror-Greedy-oror-Simple-Approach

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n,INT_MAX);
        hash[0]= 0;
        for(int i=0;i<n;i++) {
            for(int j=i + 1;j<=min(n - 1, nums[i] + i); j++) {
                hash[j] = min(hash[j], hash[i] + 1);
            } 
        }
        return hash[n - 1];
    }
};