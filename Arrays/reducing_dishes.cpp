// problem link --> https://leetcode.com/problems/reducing-dishes/
// my solution link --> https://leetcode.com/problems/reducing-dishes/discuss/3356761/C%2B%2B-oror-100-faster-oror-O(nlogn)-time-oror-O(1)-space-oror-No-DP

// O(nlogn) time || O(n) space

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res = 0, n = satisfaction.size(), val = 0;
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> suff(n); suff[n-1] = satisfaction[n-1]; 
        for(int i=n-2;i>=0;i--) suff[i] = satisfaction[i] + suff[i+1];
        for(int i=n-1;i>=0;i--) {
            res = max(res, suff[i] + val);
            val += suff[i];
        }
        return res;
    }
};


// O(nlogn) time || O(1) space

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res = 0, n = satisfaction.size(), val = 0, sum = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for(int i=n-1;i>=0;i--) {
            sum += satisfaction[i];
            res = max(res, sum + val);
            val += sum;
        }
        return res;
    }
};