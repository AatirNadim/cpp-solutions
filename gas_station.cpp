// problem link --> https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), res = 0, curr = 0;
        int sum_gas = 0, sum_cost = 0;
        for(int i=0;i<n;i++) {
            curr += (gas[i] - cost[i]);
            if(curr < 0) curr = 0, res = i+1;
            sum_gas += gas[i], sum_cost += cost[i];
        }
        return (sum_gas < sum_cost) ? -1 : res;
    }
};