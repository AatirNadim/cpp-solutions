// problem link --> https://leetcode.com/problems/add-to-array-form-of-integer/

// my solution link --> https://leetcode.com/problems/add-to-array-form-of-integer/discuss/3189319/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        int carry = 0, to_add = 0, idx = 0;
        while(idx < n and (k or carry)) {
            to_add = k%10;
            nums[idx] += to_add + carry;
            carry = nums[idx]/10; nums[idx]%= 10;
            k/=10; idx++;
        }
        while(k) {
            to_add = k%10 + carry;
            carry = to_add/10, k/=10;
            nums.push_back(to_add%10);          
        }
        if(carry) nums.push_back(carry);
        reverse(nums.begin(),nums.end());
        return nums;
    }
};