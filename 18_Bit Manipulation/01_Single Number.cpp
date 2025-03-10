// Question Link :- https://leetcode.com/problems/single-number
// Single Number


// Better Approach
// T.C = O(N*logM) + O(M) or O(N) + O(M) for unordered_map
// S.C = O(M)  where M = size of the map i.e. M = (N/2)+1.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto it : mpp) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return -1;
    }
};


// Optimal Solution
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i=0; i<nums.size(); i++) {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};