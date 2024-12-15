/*
    problem link --> https://leetcode.com/problems/maximum-average-pass-ratio/

    my solution link --> https://leetcode.com/problems/maximum-average-pass-ratio/discuss/6148380/C%2B%2B-oror-Max-Heap-oror-Intuitive

*/

class Solution {
    
    double changePossible(double avg, double n) {
        return (avg*n + 1)/(n + 1) - avg;
    }
    double getAvgFromChange(double change, double n) {
        return 1 - change*(n + 1);
        
    }
    
public:
    typedef pair<double, double> pi;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pi> pq;
        double res = 0;
        for(vector<int>& cl: classes) {
            pq.push({ changePossible(cl[0]/(double)cl[1], cl[1]), cl[1] });
        }
        while(extraStudents--) {
            pi currnode = pq.top(); pq.pop();
            // for the node, which benefits the most with an added student, 
            // we add it and insert it with the potential for the next student to be added
            double new_n = currnode.second + 1;
            
            double a1 = getAvgFromChange(currnode.first, currnode.second);
            
            double new_avg = (a1*currnode.second + 1)/(currnode.second + 1);
            
            pq.push({ changePossible(new_avg, new_n), new_n});
        }
        while(pq.size()) {
            pi currnode = pq.top(); pq.pop();
            res += getAvgFromChange(currnode.first, currnode.second);
        }
        return res/classes.size();
    }
};