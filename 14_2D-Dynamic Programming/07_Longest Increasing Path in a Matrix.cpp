// Question Link :- https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
// Longest Increasing Path in a Matrix


// Approach - 1 : DFS
// T.C = O(4^(m*n))
// S.C = O(m*n)
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, int m, int n) {
        if(i<0 || i>=m || j<0 || j>=n) {
            return 0;
        }

        int maxLen = 1;
        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, -1, 0, 1};

        for(int k=0; k<4; k++) {
            int i_ = i + di[k];
            int j_ = j + dj[k];
            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && matrix[i_][j_] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(i_, j_, matrix, m, n));
            }
        }
        return maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans = max(ans, dfs(i, j, matrix, m, n));
            }
        }
        return ans;
    }
};



// Approach - 2 : DFS + DP
// T.C = O(m*n)
// S.C = O(m*n)
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int n) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int maxLen = 1;
        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, -1, 0, 1};

        for(int k=0; k<4; k++) {
            int i_ = i + di[k];
            int j_ = j + dj[k];
            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && matrix[i_][j_] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(i_, j_, matrix, dp, m, n));
            }
        }

        return dp[i][j] = maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans = max(ans, dfs(i, j, matrix, dp, m, n));
            }
        }
        return ans;
    }
};