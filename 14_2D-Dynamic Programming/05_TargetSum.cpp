// Question Link :- https://leetcode.com/problems/target-sum/
// Target Sum

// Tabulation Method
// T.C = O(n*sum(arr))
// S.C = O(sum(arr))
class Solution {
public:
    int CountSubsetsWithSum(vector<int>& arr, int n, int sum) {
	    int t[n + 1][sum + 1];
	    for (int i = 0; i <= n; i++) {
		    for (int j = 0; j <= sum; j++) {
			    if (i == 0) {
				    t[i][j] = 0;
                }
			    if (j == 0) {
				    t[i][j] = 1;
                }
		    }
	    }
	    for (int i = 1; i <= n; i++) {
		    for (int j = 0; j <= sum; j++) {
			    if (arr[i - 1] <= j) {
				    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; 
                } else {
				    t[i][j] = t[i - 1][j];
                }
		    }
	    }
	    return t[n][sum]; 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        if(sum<target || (sum + target)%2 != 0) {
            return 0;
        }
        return CountSubsetsWithSum(nums, n, (sum + target)/2);
    }
};



// Memoization Method
// T.C = O(n*sum(arr))
// S.C = O(n*sum(arr))
class Solution {
    public:
        int mod = 1e9 + 7;
    
        int CountSubsetsWithSum(vector<int>& arr, int target, int n, vector<vector<int>>& dp) {
            if(n == 0) {
                if(target == 0) {
                    return 1;
                }
                return 0;
            }
    
            if(dp[n][target] != -1) {
                return dp[n][target];
            }
            if(arr[n-1] <= target) {
                dp[n][target] = (CountSubsetsWithSum(arr, target-arr[n-1], n-1, dp) + CountSubsetsWithSum(arr, target, n-1, dp))%mod;
            } else {
                dp[n][target] = (CountSubsetsWithSum(arr, target, n-1, dp))%mod;
            }
            return dp[n][target];
        }
    
        int findTargetSumWays(vector<int>& nums, int target) {
            target = abs(target);
            int n = nums.size();
            int sum = 0;
            for(int i=0; i<n; i++) {
                sum += nums[i];
            }
            if(sum<target || (sum + target)%2 != 0) {
                return 0;
            }
            int currTarget = (sum + target)/2;
            vector<vector<int>>dp (n+1, vector<int>(currTarget+1, -1));
        
            return CountSubsetsWithSum(nums, currTarget, n, dp);
        }
    };