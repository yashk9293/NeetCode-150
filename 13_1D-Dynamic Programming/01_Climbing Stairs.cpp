// Question Link :- https://leetcode.com/problems/climbing-stairs/
// Climbing Stairs

// Approach 1 - Recursion (TLE)
// T.C = O(2^n)
// S.C = O(n), as the maximum depth of the recursion tree is n.
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};



// Approach 2 - Memoization
// T.C = O(N)
// S.C = O(N) - We are using a recursion stack space(O(N)) and an array (again O(N)).
class Solution {
public:
    int solve(int n, vector<int>&dp) {
        if(n==0 || n==1) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n, dp);
    }
};





// Approach 3 - Bottom up (Tabulation)
// T.C = O(N)
// S.C = O(N) - We are using an external array of size ‘n+1’.
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }
        vector<int>dp(n+1);

        // dp[i] = total ways to climb i stairs
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};




// Approach 4 - Space Optimization
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }
        int c;
        int a = 1, b = 1;
        for(int i = 2; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};