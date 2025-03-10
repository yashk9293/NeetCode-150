// Question Link :- https://leetcode.com/problems/subsets/
// Subsets


// Approach - 1 (Bit Manipulation)
// T.C = O(n*2^n)
// S.C = O(n*2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<(1<<n); i++) {   // for (int num = 0; num < pow(2,n); num++)
            vector<int> output;
            for(int bit=0; bit<n; bit++) {
                //check if the ith bit is set or not
                if(i & (1<<bit)){
                    output.push_back(nums[bit]);
                }
            }
            ans.push_back(output);
        }
        return ans;
    }
};




// Approach - 2 (Recursion)
// T.C = O(n*2^n)
// S.C = O(n*2^n)
class Solution {
    private:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& output) {
        // base case
        if(i>=nums.size()) {
            ans.push_back(output);
            return;
        }
        // include
        output.push_back(nums[i]);
        solve(nums, i+1, ans, output);
        output.pop_back();

        // exclude
        solve(nums, i+1, ans, output);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, 0, ans, output);
        return ans;
    }
};