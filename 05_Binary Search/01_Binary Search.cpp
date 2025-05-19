// Question Link :- https://leetcode.com/problems/binary-search/
// Binary Search

// Recursive
// T.C = O(logN)
// S.C = O(1) excluding stack space
class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        if(l > r) {
            return -1;
        }
        int mid = l + (r-l)/2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            return binarySearch(nums, mid+1, r, target);
        }
        else {
            return binarySearch(nums, l, mid-1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums, 0, n-1, target);
    }
};





// Iterative
// T.C = O(logN)
// S.C = O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mid = 0;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return -1;
    }
};