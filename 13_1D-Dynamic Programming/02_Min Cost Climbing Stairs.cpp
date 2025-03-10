// Question Link :- https://leetcode.com/problems/min-cost-climbing-stairs
// Min Cost Climbing Stairs

// Recursion
// T.C = O(2^n)
// S.C = O(n)
class Solution {
    public:
        int solve(vector<int>& cost, int ind) {
            if (ind == 0 || ind == 1) {  // Base case
                return cost[ind];
            }
            int jumpOne = cost[ind] + solve(cost, ind - 1);
            int jumpTwo = cost[ind] + solve(cost, ind - 2);
    
            return min(jumpOne, jumpTwo);
        }
        
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            return min(solve(cost, n - 1), solve(cost, n - 2));
        }
    };
    


// Memoization
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int solve(vector<int>& cost, int ind, vector<int>& dp) {
        if (ind == 0 || ind == 1) {  // Base case
            return cost[ind];
        }
        if (dp[ind] != -1) {
            return dp[ind]; 
        }
        int jumpOne = cost[ind] + solve(cost, ind - 1, dp);
        int jumpTwo = cost[ind] + solve(cost, ind - 2, dp);

        return dp[ind] = min(jumpOne, jumpTwo);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
};



// Tabulation
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i=2; i<n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};


// Space Optimization
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int c;
        int a = cost[0], b = cost[1];

        for (int i=2; i<n; i++) {
            c = cost[i] + min(a, b); // current
            a = b;
            b = c;
        }
        return min(a, b);
    }
};
    