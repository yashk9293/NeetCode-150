// Question Link :- https://leetcode.com/problems/interleaving-string/
// Interleaving String


// T.C = O()
// S.C = O()
class Solution {
public:
    bool solve(const string &a, const string &b, const string &c, int x, int y, vector<vector<int>> &dp) {
        if (x == 0 && y == 0) {
            return true;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        bool ans = false;
        if (x > 0 && a[x - 1] == c[x + y - 1]) {
            ans = solve(a, b, c, x - 1, y, dp);
        }
        if(ans == true) {
            return dp[x][y] = ans;
        }
        if (y > 0 && b[y - 1] == c[x + y - 1]) {
            ans = solve(a, b, c, x, y - 1, dp);
        }

        return dp[x][y] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size(), y = s2.size();
        if (x + y != s3.size()) {
            return false;
        }
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return solve(s1, s2, s3, x, y, dp);
    }
};
