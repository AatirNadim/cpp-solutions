/*
    problem link --> https://leetcode.com/problems/continuous-subarrays/

    my solution link --> https://leetcode.com/problems/continuous-subarrays/discuss/6147238/C%2B%2B-oror-O(n)-time-oror-O(1)-space-oror-Simple-and-Easy

*/

class Solution {
    
    bool inRange(map<int, int>& mp, set<int, greater<int>>& st, int val) {
        int minval = mp.begin() -> first;
        int maxval = *st.begin();
        return val - minval <= 2 and maxval - val <= 2;
    }
    
    void remove(map<int, int>& mp, set<int, greater<int>>& st, int val) {
        mp[val]--;
        if(!mp[val]) {
            st.erase(val);
            mp.erase(val);
        }
    }
    
public:
    // keep track of min, max at all times, for the starting, a simple map should suffice
    // for the ending, a set --> decreasing order
    // when we add a number, if it lies in the range, great, we increase freq by 1, else we start removing all the elements from the left and keep decreasing the 
    
    
    typedef long long ll;
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> mp;
        set<int, greater<int>> st;
        int left = 0, idx = 0, n = nums.size(); ll res = 0;
        while(idx < n) {
            mp[nums[idx]]++;
            st.insert(nums[idx]);
            while(left < idx and !inRange(mp, st, nums[idx])) {
                remove(mp, st, nums[left]);
                left++;
            }
            res += (idx - left + 1);
            idx++;
        }
        return res;
    }
};