// problem link --> https://leetcode.com/problems/kth-largest-element-in-a-stream/

// my solution link --> https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/3555662/C%2B%2B-oror-Priority_Queue-oror-Short-and-Simple


class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int& i : nums) {
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */