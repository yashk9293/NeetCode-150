// Question Link :- https://leetcode.com/problems/missing-number/
// Missing Number

// T.C = O(n)
// S.C = O(1)


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = n*(n+1)/2;
        int y = accumulate(nums.begin(), nums.end(), 0);
        return x-y;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i=0; i<nums.size(); i++) {
            ans = ans ^ nums[i] ^ i;
        }
        return ans;
    }
};