// Question Link :- https://leetcode.com/problems/house-robber-ii/description/
// House Robber II

// Brute Force (Recursion) [TLE]
// T.C = O(2^n)
// S.C = O(n)
class Solution {
public:
    int solve(vector<int>& nums, int i) {
        if(i >= nums.size()) {
            return 0;
        }
        int steal = nums[i] + solve(nums, i+2); 
        int skip = solve(nums, i+1);  
        
        return max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
		if(n==1) {
            return nums[0];
        }
        
		vector<int>nums1, nums2;
		for(int i=0; i<n; i++){
			if(i != n-1) {  // (0, n-2)
                nums1.push_back(nums[i]);
            }
            if(i != 0) {  // (1, n-1)
                nums2.push_back(nums[i]);
            }
		}
		return max(solve(nums1, 0), solve(nums2, 0));
    }
};




// Approach 2 (Recursion + Memoization)
// T.C = O(n)
// S.C = O(n) + O(n) [recursive stac + dp]
class Solution {
public:
    int solve(vector<int>& nums, int i, int t[]) {
        if(i >= nums.size()) {
            return 0;
        }
        if(t[i] != -1) {
            return t[i];
        }
        int take = nums[i] + solve(nums, i+2, t);
        int skip = solve(nums, i+1, t);
        
        return t[i] = max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        
        vector<int>nums1, nums2;
		for(int i=0; i<n; i++){
			if(i != n-1) {  // (0, n-2)
                nums1.push_back(nums[i]);
            }
            if(i != 0) {  // (1, n-1)
                nums2.push_back(nums[i]);
            }
		}
        int t[101];
        memset(t, -1, sizeof(t));
        int take_0th = solve(nums1, 0, t);
        
        memset(t, -1, sizeof(t));
        int take_1th = solve(nums2, 0, t);

		return max(take_0th, take_1th);
    }
};


// if you dont want to use nums1 and nums vector - [preferred for memoization]
class Solution {
public:
    int solve(vector<int>& nums, int i, int n, int t[]) {
        if(i > n) {
            return 0;
        }
        if(t[i] != -1) {
            return t[i];
        }
        int take = nums[i] + solve(nums, i+2, n, t);
        int skip = solve(nums, i+1, n, t);
        
        return t[i] = max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }

        int t[101];
        memset(t, -1, sizeof(t));
        int take_0th = solve(nums, 0, n-2, t);
        
        memset(t, -1, sizeof(t));
        int take_1th = solve(nums, 1, n-1, t);

        return max(take_0th, take_1th);
    }
};





// Approach 3 - Tabulation [preferred fot tabulation method]
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int solve(const vector<int>& nums) {   // house robber 1 function
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
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(solve(vector<int>(nums.begin() + 1, nums.end())), 
                    solve(vector<int>(nums.begin(), nums.end() - 1)));
    }
};




// if you dont want to use nums1 and nums vector
class Solution {
public:
    int solve(const vector<int>& nums, int n, int start) {
        vector<int> dp(n, 0);  // since the size is already reduced by 1, as we are checking from (0 to n-2) and (1 to n-1)
        dp[0] = 0;
        dp[1] = nums[start];

        for (int i=2; i<n; i++) {
            int steal = nums[start + i-1] + dp[i-2];
            int skip  = dp[i-1];
            dp[i] = max(skip, steal);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(solve(nums, n, 0), solve(nums, n, 1));
    }
};
    