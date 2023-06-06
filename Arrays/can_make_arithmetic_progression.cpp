// problem link --> https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// my solution link --> https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/3605574/C%2B%2B-oror-Short-and-Simple


class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int d = arr[1] - arr[0];
        for(int i=1;i<n-1;i++) {
            if(d - (arr[i+1] - arr[i])) return 0;
        }
        return 1;
    }
};