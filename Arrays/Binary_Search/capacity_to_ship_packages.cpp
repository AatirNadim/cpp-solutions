// problem link --> https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// my solution link --> https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/3219425/C%2B%2B-oror-0ms-oror-Binary-Search-oror-Short-and-Simple

class Solution {
public:
    int func(vector<int>& weights, int val) {
        int res = 0, curr = 0;
        for(int& i : weights) {
            if(curr + i > val) {
                curr= 0, res++;
            }
            curr += i;
        }
        return res + 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int minval = *max_element(weights.begin(), weights.end());
        int maxval = accumulate(weights.begin(), weights.end(), 0);
        int medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            int val = func(weights, medval);
            if(val > days) minval = medval + 1;
            else maxval = medval - 1;
        }
        return minval;
    }
};