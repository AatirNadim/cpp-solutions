/*
    problem link --> https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/

class Solution {
    
    void mergeSort(vector<int>& arr, int left, int right) {
        if(left >= right) return;
        int l1 = left, r1 = (right + left)/2;
        int l2 = (left + right)/2 + 1, r2 = right;
        mergeSort(arr, l1, r1);
        mergeSort(arr, l2, r2);
        vector<int> temp;
        while(l1 <= r1 and l2 <= r2) {
            if(arr[l2] < arr[l1]) {

                // count the number of the values that are present in the lower array
                // which are greater than the current element in the upper array
                res += (r1 - l1 + 1);
                temp.push_back(arr[l2++]);
            } else temp.push_back(arr[l1++]);
        }
        while(l1 <= r1) {
            temp.push_back(arr[l1++]);
        }
        while(l2 <= r2) {
            temp.push_back(arr[l2++]);
        }
        for(int i = left;i <= right;i++) {
            arr[i] = temp[i - left];
        }
    }
    
  public:
    // Function to count inversions in the array.
    
    int res = 0;
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        mergeSort(arr, 0, arr.size() - 1);
        return res;
    }
};