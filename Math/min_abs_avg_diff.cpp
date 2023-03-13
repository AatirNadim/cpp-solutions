// problem link --> https://leetcode.com/problems/minimum-average-difference/

// my solution link --> https://leetcode.com/problems/minimum-average-difference/discuss/2878011/C%2B%2B-oror-O(n)-time-oror-O(1)-space-oror-97-less-memory


#define ll long long int
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll left = 0, right= 0, val;
        for(int i : nums) left += (ll)i;
        int n = nums.size(), curr = left/n, res = n - 1;
        for(int i=n-1;i>=1;i--) {
            left -= nums[i], right += nums[i];
            val = abs(left/(i) - right/(n - i));
            if(curr >= val) {
                curr = val, res = i-1;
            }
        }
        return res;
    }
};