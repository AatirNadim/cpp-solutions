// problem link --> https://leetcode.com/problems/ipo/

// my solution link --> https://leetcode.com/problems/ipo/discuss/3221246/C%2B%2B-oror-Heap-oror-Priority_Queue-oror-Sorting-oror-Greedy-oror-Short-and-Simple

class Solution {
public:
    static bool compt(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> hash;
        int n = profits.size();
        for(int i=0;i<n;i++) {
            hash.push_back({profits[i], capital[i]});
        }
        sort(hash.begin(), hash.end(), compt);
        int idx = 0, res = w;
        priority_queue<int> pq;
        while(idx < n and hash[idx][1] <= res) pq.push(hash[idx++][0]);
        while(idx < n and pq.size() and k) {
            res += pq.top(); pq.pop(); k--;
            while(idx < n and hash[idx][1] <= res) pq.push(hash[idx++][0]);
            
        }
        while(pq.size() and k) {
            res += pq.top(); pq.pop(); k--;
        }
        return res;
        
    }
};