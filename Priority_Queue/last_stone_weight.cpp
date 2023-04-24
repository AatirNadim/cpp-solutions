// problem link --> https://leetcode.com/problems/last-stone-weight/

// my solution link --> https://leetcode.com/problems/last-stone-weight/discuss/3449131/C%2B%2B-oror-0ms-oror-Short-and-Simple


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int& i : stones) pq.push(i);
        while(pq.size() > 1) {
            int val1 = pq.top(); pq.pop();
            int val2 = pq.top(); pq.pop();
            if(val2 - val1) pq.push(val1 - val2);
        }
        return pq.size() ? pq.top() : 0;
    }
};