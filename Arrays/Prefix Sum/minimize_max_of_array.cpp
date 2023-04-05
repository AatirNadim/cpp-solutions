// problem link --> https://leetcode.com/problems/minimize-maximum-of-array/

// my solution link --> https://leetcode.com/problems/minimize-maximum-of-array/discuss/3383405/C%2B%2B-oror-97-faster-oror-O(n)-time-oror-O(1)-space-oror-Short


#define ll long long int
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
		//total_yet for the entire sum till now
		//curr_yet for the sum of the consequent subarray
        ll total_yet = nums[0], curr_yet = 0;
        int max_idx = 0,  idx = 1; ll res = nums[0];
        while(idx < n) {
            total_yet+= nums[idx]; curr_yet += nums[idx];
	// determine whether the current average is greater than or equal to the current final result
            double curr_avg = curr_yet/(double)(idx - max_idx);
            if(curr_avg >= res) {
                max_idx = idx;
                curr_yet = 0;
	// update the final result after evening out the values
                res = (total_yet)/(idx + 1) + (total_yet%(idx + 1) != 0);
            }
            idx++;
        }
        return (int)res;
    }
};