// problem link --> https://leetcode.com/problems/single-element-in-a-sorted-array/

// my solution link --> https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/3214595/C%2B%2B-oror-Binary-Search-oror-Short-and-Simple

class Solution {
public:
    bool func(vector<int>& arr, int& medval) {
        int n = arr.size();
        return (medval == n-1 or arr[medval] - arr[medval + 1]) and (!medval or arr[medval] - arr[medval- 1]); 
    }
    int singleNonDuplicate(vector<int>& arr) {
        int minval = 0, maxval = arr.size() - 1, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(func(arr, medval)) return arr[medval];
            if(medval&1 and arr[medval - 1] == arr[medval]) minval = medval + 1;
            else if(!(medval&1) and arr[medval] == arr[medval + 1]) minval = medval + 1; 
            else maxval = medval - 1;
        }
        return -1;
    }
};