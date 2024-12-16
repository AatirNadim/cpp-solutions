/*
    problem link --> https://www.geeksforgeeks.org/problems/peak-element/1
*/

class Solution {
    
    bool isPeak(vector<int>& arr, int idx) {
        return (!idx or arr[idx] > arr[idx - 1]) and 
        (idx == arr.size() - 1 or arr[idx] > arr[idx + 1]);
    }
    
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int minval = 0, maxval = arr.size() - 1, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(isPeak(arr, medval)) return medval;
            else if(medval and arr[medval - 1] > arr[medval]) maxval = medval - 1;
            else minval = medval + 1;
        }
        return medval;
    }
};