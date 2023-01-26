// problem link --> https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    bool isSmall(char c) {
        return c >= 'a' and c <= 'z';
    }
    void update(vector<int>& hash, int& idx) {
        hash[idx]--;
        if(hash[idx]) return;
        while(idx < 26 and !hash[idx]) idx++;
    }
    string caseSort(string str, int n) {
        string res = "";
        vector<int> small_hash(26), big_hash(26);
        for(char c : str) {
            if(isSmall(c)) small_hash[c - 'a']++;
            else big_hash[c - 'A']++;
        }
        int left = 0, right = 0;
        while(left < 26 and !small_hash[left]) left++;
        while(right < 26 and !big_hash[right]) right++;
        for(char c : str) {
            if(isSmall(c)) {
                res.push_back(char(left + 'a'));
                update(small_hash, left);
            }
            else {
                res.push_back(char(right + 'A'));
                update(big_hash, right);
            }
        }
        return res;
    }
};