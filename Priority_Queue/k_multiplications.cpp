/*
    problem link --> https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
*/

class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(int i=0;i<nums.size();i++) {
            pq.push({ nums[i], i });
        }
        while(k--) {
            pi currnode = pq.top(); pq.pop();
            currnode.first *= multiplier;
            pq.push(currnode);
        }
        while(pq.size()) {
            pi currnode = pq.top(); pq.pop();
            nums[currnode.second] = currnode.first;
        }
        return nums;
    }
};