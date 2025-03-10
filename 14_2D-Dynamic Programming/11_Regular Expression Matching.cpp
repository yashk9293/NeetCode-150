// Question Link :- https://leetcode.com/problems/regular-expression-matching/
// Regular Expression Matching

// Similar to Wildcard Matching

// T.C = O(n*m)
// S.C = O(n*m) + O(n+m) -> 2d dp array + recursion stack
class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) {     // both string exhausted
            return true;
        }
        else if(j < 0 && i >= 0) {    // string p is exhausted
            return false;
        }
        // imp base case now
        else if(i < 0 && j >= 0) {    // string s is exhausted
            
        // * ke pehle character hona chahiye tabhi * uss character ko match karega
            
            for(int k = 0; k <= j; k+= 2) { // yaha +2 isliye kar rhe kyuki hume sirf * wala position dekhna hai 
                if(p[k+1] != '*') {  // kyuki 0th position me kabhi * nhi ho sakta, isliye 1st position se check
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '.') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        else if(p[j] == '*') {
            bool takenull = solve(i, j - 2, s, p, dp); // here j-2 because if we not take * then, we also have to skip it's preceeding character
            bool takeone = (s[i] == p[j - 1] || p[j - 1] == '.') && solve(i - 1, j, s, p, dp);

            return dp[i][j] = takeone || takenull;
        }
        return dp[i][j] = false;  // agar koi character s aur p me match nhi kiya to
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, s, p, dp);
    }
};