// problem link --> https://leetcode.com/problems/data-stream-as-disjoint-intervals/

// my solution link --> https://leetcode.com/problems/data-stream-as-disjoint-intervals/discuss/3108332/C%2B%2B-oror-Binary-Seach-oror-Union

class SummaryRanges {
public:
    vector<vector<int>> res;
    unordered_map<int, bool> mp;
    SummaryRanges() {
        res.clear();
        mp.clear();
    }
    void addNum(int value) {
        int n = res.size();
        if(mp[value]) return;
        int previdx = -1, nextidx = -1;
        int minval = 0, maxval = n-1, medval;
        while(minval <= maxval) {
            medval = minval+ ((maxval- minval)>>1);
            if(res[medval][1] == value - 1) {
                previdx = medval; break;
            }
            else if(res[medval][1] < value - 1) minval = medval + 1;
            else maxval = medval - 1;
        }
        minval = 0, maxval = n-1;
        while(minval <= maxval) {
            medval = minval+ ((maxval- minval)>>1);
            if(res[medval][0] == value + 1) {
                nextidx = medval; break;
            }
            else if(res[medval][0] < value + 1) minval = medval + 1;
            else maxval = medval - 1;
        }
        vector<vector<int>> temp;
        int left = (previdx + 1) ? res[previdx][0] : value;
        int right = (nextidx + 1) ? res[nextidx][1] : value;
        int idx = 0;
        while(idx < n and res[idx][1] < left) temp.push_back(res[idx++]);
        temp.push_back({left, right});
        while(idx < n and res[idx][0] <= right) idx++;
        while(idx < n) temp.push_back(res[idx++]);
        mp[value] = 1;
        res = temp;
    }
    
    vector<vector<int>> getIntervals() {
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */