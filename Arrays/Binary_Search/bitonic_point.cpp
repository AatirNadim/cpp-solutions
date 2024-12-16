/*
    problem link --> https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1
*/

class Solution {
    
    bool increasing(vector<int>& arr, int idx, int& n) {
        return (!idx or arr[idx - 1] <= arr[idx]) and 
        (idx == n - 1 or arr[idx] <= arr[idx + 1]);
    }
    
    bool decreasing(vector<int>& arr, int idx, int& n) {
        return (!idx or arr[idx - 1] >= arr[idx]) and 
        (idx == n - 1 or arr[idx] >= arr[idx + 1]);
    }
    
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int minval = 0, maxval = arr.size() - 1, medval, n = arr.size();
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(increasing(arr, medval, n)) minval = medval + 1;
            else if(decreasing(arr, medval, n)) maxval = medval - 1;
            else break;
        }
        return arr[medval];
    }
};