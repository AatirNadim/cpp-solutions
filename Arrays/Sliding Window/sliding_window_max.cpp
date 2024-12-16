/*
    problem link --> https://leetcode.com/problems/sliding-window-maximum/
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