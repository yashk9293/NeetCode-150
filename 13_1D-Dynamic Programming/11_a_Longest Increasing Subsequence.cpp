// Question Link :- https://leetcode.com/problems/longest-increasing-subsequence/
// Longest Increasing Subsequence


// Recursion (giving TLE)
// T.C = O(2^n)
// S.C = O(n)
class Solution {
public:
    int lis(vector<int>& nums, int i, int prev) {
        if(i == nums.size()) {
            return 0;
        }
        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]) {
            take = 1 + lis(nums, i+1, i);
        }
        int skip = lis(nums, i+1, prev);
        
        return max(take, skip);     
    }

    int lengthOfLIS(vector<int>& nums) {
        return lis(nums, 0, -1);
    }
};






// Memoization
// T.C = O(n^2)
// S.C = O(n^2)
class Solution {
public:
    int t[2501][2501];
    int lis(vector<int>& nums, int i, int prev) {
        if(i == nums.size()) {
            return 0;
        }
        if(prev != -1 && t[i][prev] != -1) {
            return t[i][prev];
        }
        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]) {   // prev == -1 means no elements had been taken till now
            take = 1 + lis(nums, i+1, i);
        }
        int skip = lis(nums, i+1, prev);
        
        if(prev != -1) {
            t[i][prev] =  max(take, skip);
        }
        return max(take, skip);     
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return lis(nums, 0, -1);
    }
};





// Bottom Up
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j] + 1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        return maxL;
    }
};