// Question Link :- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Find Minimum in Rotated Sorted Array

// T.C = O(logN)
// S.C = O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return nums[l]; // or nums[r]
    }
};