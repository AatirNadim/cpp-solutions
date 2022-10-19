//question link --> https://leetcode.com/problems/top-k-frequent-words/description/
//my solution link --> https://leetcode.com/problems/top-k-frequent-words/solutions/2722372/c-custom-comparator-priority-queue/

//please note the novel implementation for the custom comparator.
//hope this method proves catalyst in further possible complex scenarios.

class pi {
    public:
    int val; string s;
    pi (int val ,string s) {
        this->val= val; this->s = s;
    }
    bool operator < (const pi& pi1) const {
        if(val == pi1.val) {
            return s.compare(pi1.s) < 0;
        }
        return val > pi1.val;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string &s : words) mp[s]++;
        priority_queue<pi> pq;
        for(auto &p : mp) {
            pq.push(pi(p.second, p.first));
            if(pq.size() > k) pq.pop();
        }
        vector<string> res;
        while(pq.size()) {
            res.push_back(pq.top().s), pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};