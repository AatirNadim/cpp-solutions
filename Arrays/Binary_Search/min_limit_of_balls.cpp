/*
    problem link --> https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
*/


class Solution {
    
    // find whether the current possible penalty, when applied, requires no of operations not greater than the max limit
    bool isPossible(vector<int>& nums, int curr, int& maxOperations) {
        int res = 0;
        for(int & i: nums) {
            res += (i/curr - (i%curr == 0));
        }
        return res <= maxOperations;
    }
    
public:
    /*
    since there is no pattern to determine the min penalty from the array itself
    we consider potential penalties and determine the number of operations they require
    as long as the total no of operations are within the limit, we can check for lesser penalties
    */
    int minimumSize(vector<int>& nums, int maxOperations) {
        int minval = 1, maxval = -1, medval;
        for(int& i: nums)
            maxval = max(maxval, i);
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(isPossible(nums, medval, maxOperations)) maxval = medval - 1;
            else minval = medval + 1;
        }
        return minval;
    }
};