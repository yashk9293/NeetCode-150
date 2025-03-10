// Question Link :- https://leetcode.com/problems/jump-game-ii
// Jump Game II


// Memoization
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    int solve(int idx, int n, vector<int>& nums, vector<int>& dp) {
        if(idx >= n - 1) {
            return 0;    // when we reach end, return 0 denoting no more jumps required
        }
        if(dp[idx] != 10001) {
            return dp[idx];
        }
        // explore all possible jump sizes from current position.
        for(int i = 1; i <= nums[idx]; i++) {
            dp[idx] = min(dp[idx], 1 + solve(idx + i, n, nums, dp));
        }        
        return dp[idx];
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10001); // initialise all to max possible jumps + 1 denoting dp[i] hasn't been computed yet
        return solve(0, n, nums, dp);
    }
};




// Optimal Solution
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0;
        int r = 0;
        
        while (r < n - 1) {
            int far = 0;
            for (int i = l; i <= r; i++) {
                far = max(far, i + nums[i]);
            }
            l = r + 1;
            r = far;
            jumps++;
        }
        return jumps;
    }
};