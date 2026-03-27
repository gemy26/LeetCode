class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startPos = 0, n = gas.size();
        int currGas = 0, totalGas = 0;

        for (int i = 0; i < n; i++) {
            currGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];
            if (currGas < 0) {
                currGas = 0;
                startPos = i + 1;
            }
        }
        return (totalGas < 0) ? -1 : startPos;
    }
};