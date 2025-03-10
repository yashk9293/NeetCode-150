// Question Link :- https://leetcode.com/problems/longest-increasing-subsequence/
// Longest Increasing Subsequence

// Patience Sorting
// T.C = O(nlogn)
// S.C = O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        for(int i = 0; i<n; i++) {
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if(it == sorted.end()) {
                sorted.push_back(nums[i]); //greatest : so insert it
            } else {
                *it = nums[i]; //replace
            }
        }
        return sorted.size();
    }
};

/*
    Why lower bound ?
    We want increasing subsequence and hence we want to eliminate the duplicates as well.
    lower_bound returns iterator to "next greater or equal to"
*/






// OR writing own lower bound function
class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int l=0;
        int r = arr.size()-1;

        int ans = arr.size();
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (arr[mid] >= target) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        for(int i = 0; i<n; i++) {
            int idx = lowerBound(sorted, nums[i]);
            if(idx == sorted.size()) {
                sorted.push_back(nums[i]);  // insert
            } else {
                sorted[idx] = nums[i];  // replace
            }
        }
        return sorted.size();
    }
};