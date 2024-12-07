/*
    problem link --> https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*/

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        // left has the next possible position for one
        // right has the next possible position for two
        int n = arr.size(), left = 0, right = n - 1;
        int idx = 0;
        while(idx <= right) {
            if(arr[idx] == 0) {
                swap(arr[idx++], arr[left++]);
            } else if(arr[idx] == 2) {
                swap(arr[idx], arr[right--]);
            } else idx++;
        }
    }
};