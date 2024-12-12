/*
    problem link --> https://leetcode.com/problems/take-gifts-from-the-richest-pile/
*/

class Solution {
public:
    typedef long long ll;
    ll pickGifts(vector<int>& gifts, int k) {
        priority_queue<ll> pq;
        ll res = 0;
        for(int i: gifts) {
            pq.push(i);
        }
        // keep taking the maximum possible value from the heap, reduce it as needed and return it to the heap.

        while(pq.size() and k--) {
            ll currnode = pq.top(); pq.pop();
            pq.push(sqrt(currnode));
        }
        while(pq.size()) {
            res += pq.top(); pq.pop();
        }
        return res;
    }
};