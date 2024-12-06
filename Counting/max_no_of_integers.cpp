/*
    problem link --> https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
*/


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, bool> mp;
        // get all the banned numbers in a hash, to check during traversal later
        for(int& i: banned) mp[i] = 1;
        int curr = 1, res = 0;
        // as long as the valid numbers constitute a sum less than or equal to the maxSum and they are in range, we continue
        while(maxSum >= 0 and curr <= n) {
            if(!mp[curr]) {
                maxSum -= curr;
                res++;
            }
            curr++;
        }
        // if the maxSum limit has not been breached, the result will always be the same, else it will be just before the limit was breached
        return maxSum >= 0 ? res: res - 1;
    }
};