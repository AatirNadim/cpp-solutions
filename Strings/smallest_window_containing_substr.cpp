/*
    problem link --> https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
*/

class Solution {

    bool containsAllCharacters(vector<int>& hash1, vector<int>& hash2) {
        for(int i = 0;i<26;i++) {
            if(hash2[i] > hash1[i]) return 0;
        }
        return 1;
    }

  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        // Your code here
        vector<int> hash1(26), hash2(26);
        for(char c: s2) hash2[c - 'a']++;
        int left = 0, right = 0, n = s1.size();
        string res = "";
        while(right < n) {
            // right always has the next element to be added
            while(right < n and !containsAllCharacters(hash1, hash2)) {
                hash1[s1[right] - 'a']++;
                right++;
            }
            if(!containsAllCharacters(hash1, hash2)) break;
            // left always has the next element to be deleted
            while(left <= right and containsAllCharacters(hash1, hash2)) {
                hash1[s1[left] - 'a']--;
                left++;
            }
            if(!res.size() or res.size() > (right - left + 1)) 
            res = s1.substr(left - 1, right - left + 1);
            
        }
        return res.size() ? res: "";
        
    }
};