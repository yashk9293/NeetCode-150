// Question Link :- https://leetcode.com/problems/unique-paths/description/
// Unique Paths


// Recursion
// T.C = O(2^(mn))
// S.C - O(n)
class Solution {
public:
    int countPaths(int i, int j, int m, int n) {
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(i >= m || j >= n) {
            return 0;
        }
        return  countPaths(i+1, j, m, n) + countPaths(i, j+1, m, n);
    }

    int uniquePaths(int m, int n) {
        return countPaths(0, 0, m, n);
    }
};



// Memoization
// T.C =  O(M*N)
// S.C =  O((N-1)+(M-1)) + O(M*N)
class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(i >= m || j >= n) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return countPaths(0, 0, m, n, dp);
    }
};



// Tabulation
// T.C = O(M*N)
// S.C = O(M*N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n, 0));   // t[i][j] = total ways to reach at [i][j]
        
        // Since we start from[0][0], we move right and right so, there is only one way to reach each cell in the first row
        for(int i = 0; i<n; i++) {
            t[0][i] = 1;
        }
        // Since we start from[0][0], we move down and down so, there is only one way to reach each cell in the first column
        for(int j=0; j<m; j++) {
            t[j][0] = 1;
        }
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};