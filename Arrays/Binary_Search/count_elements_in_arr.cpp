/*
    problem link --> https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1
*/

class Solution {
    
    int findEle(vector<int>& b, int curr) {
        int minval = 0, maxval = b.size() - 1, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(b[medval] <= curr) minval = medval + 1;
            else maxval = medval - 1;
        }
        return minval;
    } 
    
  public:
    vector<int> countEleLessThanOrEqual(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(), b.end());
        vector<int> res;
        for(int& i: a) {
            res.push_back(findEle(b, i));
        }
        return res;
    }
};