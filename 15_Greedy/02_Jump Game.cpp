// Question Link :- https://leetcode.com/problems/jump-game/
// Jump Game

// Memoization
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    bool solve(int idx, int n, vector<int>& nums, vector<int>& dp) {
        if(idx == n-1) {
            return true;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        for(int i = 1; i <= nums[idx]; i++) {
            if(solve(idx+i, n, nums, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, nums, dp);
    }
};




// Optimal Solution
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachable = 0;
        
        for(int i = 0; i<n; i++) {
            if(i > maxReachable) {
                return false;
            }
            maxReachable = max(maxReachable, nums[i]+i);
        }
        return true;
    }
};