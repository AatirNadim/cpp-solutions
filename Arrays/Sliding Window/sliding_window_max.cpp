/*
    problem link --> https://leetcode.com/problems/sliding-window-maximum/

    my solution link --> https://leetcode.com/problems/sliding-window-maximum/discuss/6153057/C%2B%2B-oror-Monotonic-Deque

*/

class Solution {
    
    int findMaxIdx(vector<int>& arr, int left, int right) {
        int maxval = arr[left], res = left;
        for(int i=left; i <= right;i++) {
            if(arr[i] >= arr[res]) {
                res = i; 
            }
        }
        return res;
    }
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 1, right = k, maxidx, n = nums.size();
        maxidx = findMaxIdx(nums, 0, k - 1);
        vector<int> res;
        res.push_back(nums[maxidx]);
        // for every window, find the greatest index for the greatest element
        // we want to reduce the no of times, we have to sweep over the entire window
        while(right < n) {
            // current max element is not in the window
            if(maxidx == left - 1) {
                maxidx = findMaxIdx(nums, left, right);
            } else if (nums[right] >= nums[maxidx]) maxidx = right; // new max element in the current window
            res.push_back(nums[maxidx]);
            left++, right++;
        }
        return res;
    }
};


// More efficient approach

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> res;
        for(int i = 0;i<n;i++) {
            while(dq.size() and i - dq.front() >= k) dq.pop_front();
            while(dq.size() and nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};