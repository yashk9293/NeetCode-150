// Question Link :- https://leetcode.com/problems/gas-station/
// Gas Station


// Brute Force
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i<n; i++) {
            if(gas[i] < cost[i]) {
                continue;
            }
            int j = (i+1)%n;

            int currGas = gas[i];
            currGas = currGas - cost[i] + gas[j]; // ye currGas leke jayega jth index me
            
            while(j != i) {
                if(currGas < cost[j]) {
                    break;
                } 
                int costForMovingFromThisj = cost[j];
                
                //Let's move
                j = (j+1)%n;
                currGas = currGas - costForMovingFromThisj + gas[j];
            }

            if(i == j) {
                return i;
            }
        }
        return -1; 
    }
};





// Optimal Solution
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sumGas = accumulate(begin(gas), end(gas), 0);
        int sumCost = accumulate(begin(cost), end(cost), 0);
        if(sumGas < sumCost) {
            return -1;
        }

        int currGas  = 0;
        int startIndex = 0;
        for(int i = 0; i<n; i++) {
            currGas += gas[i] - cost[i];
            if(currGas < 0) {
                startIndex = i+1;
                currGas = 0;
            }
        }
        return startIndex;
    }
};