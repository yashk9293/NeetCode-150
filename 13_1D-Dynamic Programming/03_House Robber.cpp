// Question Link :- https://leetcode.com/problems/house-robber/
// House Robber

// Brute Force (Recursion)
// T.C = O(2^n)
// S.C = O(n), the max depth of recursion can go upto n.
class Solution {
public:
    int solve(vector<int>& nums, int i) {
        if(i >= nums.size()) {
            return 0;
        }
        int steal = nums[i] + solve(nums, i+2);  // steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, i+1);  // skips this house, now we can move to adjacent next house
        
        return max(steal, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0);
    }
};




// Approach 2 (Recursion + Memoization)
// T.C = O(n)
// S.C = O(n), required for dp and implicit recursive stack.
class Solution {
public:
    int solve(vector<int>& nums, int i, int t[]) {
        if(i >= nums.size()) {
            return 0;
        }
        if(t[i] != -1) {
            return t[i];
        }
        int take = nums[i] + solve(nums, i+2, t);  // steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, i+1, t);  // skips this house, now we can move to adjacent next house
        
        return t[i] = max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int t[101];
        memset(t, -1, sizeof(t));
        return solve(nums, 0, t);
    }
};




// Approach 3 - Bottom up (Tabulation)
// T.C = O(N)
// S.C = O(N) - We are using an external array of size ‘n+1’.
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        vector<int> t(n+1);
        // t[i] = max profit till house i
        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2; i<=n; i++) {
            int steal = nums[i-1] + t[i-2];
            int skip  = t[i-1];
            t[i] = max(skip, steal);
        }
        return t[n];
    }
};





// Approach 4 - Space Optimization
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        int prevPrev = 0;
        int prev = nums[0];
        for(int i=2; i<=n; i++) {
            int take = nums[i-1] + prevPrev;
            int skip = prev;

            int temp = max(skip, take);
            
            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
};