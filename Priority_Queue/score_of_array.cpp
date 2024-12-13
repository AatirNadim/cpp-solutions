/*
    problem link --> https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/

    my solution link --> https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/discuss/6143991/C%2B%2B-oror-Custom-Heap-oror-Easy-and-Efficient
*/

class Solution {
    class CustomNode {
        public:
        int val;
        int idx;
        CustomNode(int val, int idx) {
            this->val = val;
            this->idx = idx;
        }
        
        bool operator < (const CustomNode& otherNode) const {
            if(val == otherNode.val) return idx > otherNode.idx;
            return val > otherNode.val;
        }
    };
    
    
public:
    typedef long long ll;
    long long findScore(vector<int>& nums) {
        priority_queue<CustomNode> pq;
        int n = nums.size();
        ll res = 0;
        for(int i=0;i<n;i++) {
            pq.push(CustomNode(nums[i], i));
        }
        vector<bool> vis(n);
        while(pq.size()) {
            CustomNode currnode = pq.top(); pq.pop();
            if(vis[currnode.idx]) continue;
            vis[currnode.idx] = 1;
            if(currnode.idx > 0) vis[currnode.idx - 1] = 1;
            if(currnode.idx < n - 1) vis[currnode.idx + 1] = 1;
            res += currnode.val;
        }
        return res;
        
    }
};