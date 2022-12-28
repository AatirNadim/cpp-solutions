// problem link --> https://leetcode.com/problems/remove-stones-to-minimize-the-total/

// my solution link --> https://leetcode.com/problems/remove-stones-to-minimize-the-total/discuss/2962057/C%2B%2B-oror-Priority-Queue-(Heap)-oror-Short-and-Simple


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int res = 0;
        priority_queue <int> pq;
        for(int &i : piles) {
            res += i;
            pq.push(i);
        }
        while(k--) {
            int val = pq.top(); pq.pop();
            res -= (val>>1);
            pq.push(val - (val>>1));
        }
        return res;
    }
};