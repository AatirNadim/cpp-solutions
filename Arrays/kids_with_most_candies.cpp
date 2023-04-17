// problem link --> https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

// my solution link --> https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/discuss/3426019/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxval = 0;
        vector<bool> res;
        for(int& i : candies) maxval = max(maxval, i);
        for(int& i : candies) {
            res.push_back(i + extraCandies >= maxval);
        }
        return res;
    }
};