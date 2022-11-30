// Question link --> https://leetcode.com/problems/unique-number-of-occurrences/

// my solution link --> https://leetcode.com/problems/unique-number-of-occurrences/discuss/2862976/C%2B%2B-oror-Easy-oror-Short-and-Simple

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp1, mp2;
        for(int &i : arr) mp1[i]++;
        for(auto &p : mp1) mp2[p.second]++;
        return mp1.size() == mp2.size();
    }
};

