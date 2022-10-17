// Question link --> https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
//We have to find whether the given word contains every character in the english alphabet.
// My solution link --> https://leetcode.com/problems/check-if-the-sentence-is-pangram/solutions/2714172/c-100-faster-95-less-memory/

// I would like to draw your attention, not to the scope of the problem itself, but rather to the way it has been handled.
// It can be quite handy in further complex problems.
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> hash(26); int res = 0;
        for(char c : sentence) {
            res += !hash[c- 'a'];
            hash[c - 'a']= 1;
        }
        return res == 26;
    }
};