// Question Link :- https://leetcode.com/problems/edit-distance/
// Edit Distance

// T.C = O(m*n)
// S.C = O(m*n)

// Memoization
class Solution {
public:
    int t[501][501];
    int solve(string word1, string word2, int m, int n) {
        if(n==0) {
            return m;  // delete in word1
        } else if(m==0) {
            return n;  // insert from word1
        }
        if(t[m][n] != -1) {
            return t[m][n];
        }
        if(word1[m-1] == word2[n-1]) {
            return t[m][n] = solve(word1, word2, m-1, n-1);
        } else {
            int insertC  = 1 + solve(word1, word2, m, n-1);
            int deleteC  = 1 + solve(word1, word2, m-1, n);
            int replaceC = 1 + solve(word1, word2, m-1, n-1);
            return t[m][n] = min({insertC, deleteC, replaceC});
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        memset(t, -1, sizeof(t));
        return solve(word1, word2, m, n);
    }
};





// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1, 0));
        for(int i=0; i<=m; i++) {  // deletions from word1
            dp[i][0] = i;
        }
        for(int j=0; j<=n; j++) {  // insert in word1
            dp[0][j]= j;
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};