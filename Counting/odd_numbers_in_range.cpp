// problem link --> https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

// my solution link --> https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/discuss/3180001/C%2B%2B-oror-0ms-oror-2-line-oror-Short-and-Simple

class Solution {
public:
    int countOdds(int low, int high) {
        int dist = high - low + 1;
        return (dist>>1) + (dist&1 and low&1);
    }
};