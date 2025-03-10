// Question Link :- https://leetcode.com/problems/burst-balloons/
// Burst Balloons

// Recursion
// T.C = O(2^n)
// S.C = O(n)


// Memoization
// T.C = O(n^3)
// S.C = O(n^2)
class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& t) {
        if(i > j) {
            return 0;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        int ans = INT_MIN;
        for (int k = i; k <= j; k++) {
            int temp_ans = solve(nums, i, k-1, t) + solve(nums, k + 1, j, t) + nums[i-1] * nums[k] * nums[j+1];
            ans = max(ans, temp_ans);
        }
        return t[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> t(n, vector<int>(n, -1));

        return solve(nums, 1, n-2, t);
    }
};




// Tabulation
// T.C = O(n^3)
// S.C = O(n^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i=n-2; i>=1; i--) {
            for (int j=1; j<=n-2; j++) {
                if (i > j) {
                    continue;
                }
                int maxi = INT_MIN;
                // Iterate through each possible balloon to burst last
                for (int k = i; k <= j; k++) {
                    int coins = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
};