// problem link --> https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

// my solution link --> https://leetcode.com/problems/successful-pairs-of-spells-and-potions/discuss/3369471/C%2B%2B-oror-Binary-Search-oror-Short-and-Simple


#define ll long long int
class Solution {
public:
    int getRes(ll to_check, vector<int>& potions, long long success) {
        int minval = 0, maxval = potions.size() - 1, medval;
        while(minval <= maxval) {
            medval = minval + ((maxval - minval)>>1);
            if(potions[medval] < to_check) minval = medval + 1;
            else maxval = medval - 1;
        }
        return potions.size() - minval;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for(int& i: spells) {
            ll to_check = success/i + (success%i != 0);
            res.push_back(getRes(to_check, potions, success));
        }
        return res;
    }
};