// Question Link - https://leetcode.com/problems/two-sum/
// Two Sum (Return Index)


// Brute Force
// T.C = O(N^2)
// S.C = O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n  = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return {-1,-1};
    }
};



// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return { -1, -1};
    }
};