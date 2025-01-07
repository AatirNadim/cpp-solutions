/*
  problem link --> https://leetcode.com/problems/string-matching-in-an-array/
*/

class Solution {
 public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> matchingWords;

    for (int currentWordIndex = 0; currentWordIndex < words.size();
         currentWordIndex++) {
      vector<int> lps = computeLPSArray(words[currentWordIndex]);
      for (int otherWordIndex = 0; otherWordIndex < words.size();
           otherWordIndex++) {
        if (currentWordIndex == otherWordIndex)
          continue;
        if (isSubstringOf(words[currentWordIndex], words[otherWordIndex],lps)) {
          matchingWords.push_back(words[currentWordIndex]);
          break;
        }
      }
    }

    return matchingWords;
  }

 private:
  vector<int> computeLPSArray(string &sub) {
    vector<int> lps(sub.size(), 0); 
    int currentIndex = 1;
    int len = 0;

    while (currentIndex < sub.size()) {
      if (sub[currentIndex] == sub[len]) {
        len++;
        lps[currentIndex] = len;
        currentIndex++;
      } else {
        if (len > 0) {
          len = lps[len - 1];
        } else {
          currentIndex++;
        }
      }
    }
    return lps;
  }

  
  bool isSubstringOf(string &sub, string &main, vector<int> &lps) {
    int mainIndex = 0;
    int subIndex = 0;

    while (mainIndex < main.size()) {
      if (main[mainIndex] == sub[subIndex]) {
        subIndex++;
        mainIndex++;
        if (subIndex == sub.size()) return true;
      } else {
        if (subIndex > 0) {
          subIndex = lps[subIndex - 1];
        } else {
          mainIndex++;
        }
      }
    }
    return false;
  }
};