// problem link --> https://leetcode.com/problems/summary-ranges/

// my solution link --> https://leetcode.com/problems/summary-ranges/discuss/3628552/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    typedef long long int ll;
    string process(ll left, ll right) {
        string val1 = (left - right) ? to_string(left) + "->" + to_string(right) : "" + to_string(right);
        return val1;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> hash;
        if(!nums.size()) return {};
        int n = nums.size(), idx = 0;
        ll left = nums[0], right = nums[0], expect = nums[0];
        while(idx < n) {
            if((ll)nums[idx] != expect) {
                hash.push_back(process(left, nums[idx - 1]));
                left = nums[idx]; 
            }
            expect = (ll)nums[idx]+1; idx++;
        }
        hash.push_back(process(left, nums[idx - 1]));
        return hash;
    }
};