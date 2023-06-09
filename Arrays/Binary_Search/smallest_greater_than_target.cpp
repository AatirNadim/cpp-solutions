// problem link --> https://leetcode.com/problems/find-smallest-letter-greater-than-target/

// my solution link --> https://leetcode.com/problems/find-smallest-letter-greater-than-target/discuss/3619340/C%2B%2B-oror-Binary-Search-oror-Short-and-Simple


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int minval = 0, maxval = letters.size()-1, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(letters[medval] > target) maxval = medval - 1;
            else minval = medval + 1;
        }
        if(minval >= letters.size()) return letters[0]; 
        return letters[minval];
    }
};