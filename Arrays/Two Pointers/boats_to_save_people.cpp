// problem link --> https://leetcode.com/problems/boats-to-save-people/

// my solution links --> 

// (1) --> https://leetcode.com/problems/boats-to-save-people/discuss/3374106/C%2B%2B-oror-Sorting-oror-Binary-Search

// (2) --> https://leetcode.com/problems/boats-to-save-people/discuss/3374113/C%2B%2B-oror-Alternate-Approach-oror-Two-Pointers

// Binary Search Solution
class Solution {
public:
    bool isPossible(vector<int>& people, int no_boats, int& limit) {
        int left = 0, right = people.size() - 1;
        while(left < right and no_boats) {
            if(people[left] + people[right] <= limit) {
                left++, right--;
            }
            else right--;
            no_boats--;
        }
        if(left == right) return no_boats;
        return left > right;
    }
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int minval = 1, maxval= people.size(), medval;
        while(minval <= maxval) {
            medval = minval + ((maxval - minval)>>1);
            if(isPossible(people, medval, limit)) maxval = medval - 1;
            else minval = medval + 1;
        }
        return minval;
    }
};

// Two Pointers Solution

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1, res= 0;
        while(left < right) {
            if(people[left] + people[right] <= limit) {
                left++, right--;
            }
            else right--;
            res++;
        }
        return res + (left == right);
    }
};