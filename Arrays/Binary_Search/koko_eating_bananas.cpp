// problem link --> https://leetcode.com/problems/koko-eating-bananas/

// my solution link --> https://leetcode.com/problems/koko-eating-bananas/discuss/3271760/C%2B%2B-oror-93-faster-oror-83-less-memory-oror-Binary-Search-oror-Short-and-Simple

#define ll long long int
class Solution {
public:
    ll get_hours(vector<int>& piles, int curr) {
        ll res = 0;
        for(int& pile : piles) {
            res += pile/curr + (pile%curr != 0);
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll minval = 1, maxval = *max_element(piles.begin(), piles.end());
        ll medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(get_hours(piles, medval) <= h) maxval = medval - 1;
            else minval = medval + 1;
        }
        return (int)minval;
    }
};