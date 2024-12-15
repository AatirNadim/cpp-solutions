/*
    problem link --> https://leetcode.com/problems/distribute-candies/
*/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(int& itr: candyType) st.insert(itr);
        return min((candyType.size() >> 1), st.size());
    }
};