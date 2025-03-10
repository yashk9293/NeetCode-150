// Question Link - https://leetcode.com/problems/maximum-subarray/
// Maximum Subarray (Kadane's Algorithm)

// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};




// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN; // maximum sum
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
            }
            // If sum < 0: discard the sum calculated
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};