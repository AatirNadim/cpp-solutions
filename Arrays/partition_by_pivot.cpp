// problem link --> https://leetcode.com/problems/partition-array-according-to-given-pivot/

//my solution link --> https://leetcode.com/problems/partition-array-according-to-given-pivot/discuss/2998076/C%2B%2B-oror-The-easy-way-oror-Short-and-Simple

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        for(int& i : nums) {
            if(i < pivot) res.push_back(i);
        }
        for(int& i : nums) {
            if(i == pivot) res.push_back(i);
        }
        for(int& i : nums) {
            if(i > pivot) res.push_back(i);
        }
        return res;
    }
};