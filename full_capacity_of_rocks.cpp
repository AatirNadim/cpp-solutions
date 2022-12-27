class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for(int i=0;i<n;i++) capacity[i] -= rocks[i];
        sort(capacity.begin(), capacity.end());
        int idx = 0, res = 0;
        while(idx < n and !capacity[idx]) idx++;
        res = idx;
        while(idx < n and additionalRocks > 0) {
            if(capacity[idx] <= additionalRocks) res++;
            additionalRocks -= capacity[idx];
            idx++;
        }
        return res;
    }
};