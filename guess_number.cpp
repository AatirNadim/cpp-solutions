// Problem link --> https://leetcode.com/problems/guess-number-higher-or-lower/description/
// My solution link --> https://leetcode.com/problems/guess-number-higher-or-lower/solutions/2821394/c-binary-search-iterative-method/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int minval = 1, maxval= n, medval;
        while(minval < maxval) {
            medval= minval + (maxval - minval)/2;
            int val = guess(medval);
            if(val > 0) minval = medval + 1;
            else if(val < 0) maxval= medval - 1;
            else return medval;
        }
        return minval;
    }
};