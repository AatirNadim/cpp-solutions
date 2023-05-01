// problem link --> https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

// solution link --> https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/discuss/3474010/C%2B%2B-oror-Short-and-Simple-oror-Traversal

class Solution {
public:
    double average(vector<int>& salary) {
        int maxsal = 0, minsal = 1e6 + 1;
        double sum = 0;
        for(int& sal : salary) {
            maxsal = max(maxsal, sal);
            minsal = min(minsal, sal);
            sum += sal;
        }
        return (sum - minsal - maxsal)/(double)(salary.size() - 2);
    }
};