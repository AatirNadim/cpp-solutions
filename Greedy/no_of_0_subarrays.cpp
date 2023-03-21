// problem link --> https://leetcode.com/problems/number-of-zero-filled-subarrays/

// my solution link --> https://leetcode.com/problems/number-of-zero-filled-subarrays/discuss/3324134/C%2B%2B-oror-Math-oror-O(n)-time-O(1)-space-oror-Short-and-Simple

#define ll long long int
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size(), idx = 0; ll res = 0, temp = 0;
        while(idx < n and nums[idx]) idx++;
        while(idx < n) {
            temp = 0;
            while(idx < n and !nums[idx]) {
                res += ++temp;
                idx++;   
            }
            while(idx < n and nums[idx]) idx++;
        }
        return res;
    }
};