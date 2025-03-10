// Question Link :- https://leetcode.com/problems/subsets-ii/description/
// Subsets II


// Approach - 1 (Generating all subset and storing in set)
// T.C = O(nlogn + n*2^n)
// S.C = O(n*2^n)
class Solution {
private:
    void solve(vector<int>& nums, int i, set<vector<int>>& res, vector<int> output) {
        // base case
        if(i>=nums.size()) {
            res.insert(output);   // O(n) average case
            return;
        }
        // exclude
        solve(nums, i+1, res, output);

        // include
        output.push_back(nums[i]);
        solve(nums, i+1, res, output);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums, 0, res, output);
        // copying vectors from res to ans
        vector<vector<int>> ans;
        for(auto &vec: res) {   // O(2^n) subsets
            ans.push_back(vec);  // O(n)
        }
        return ans;
    }
};



// Approach - 2
// T.C = O(n*2^n)
// S.C = O(n*2^n)
class Solution {
private:
    void solve(vector<int>& nums, int idx, vector<int> output, vector<vector<int>>& ans) {
        ans.push_back(output);
        for(int i=idx; i<nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) {
                continue;
            }
            output.push_back(nums[i]);
            solve(nums, i+1, output, ans);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums, 0, output, ans);
        return ans;
    }
};




// Approach - 3 (Without extra space)
// T.C = O(nlogn + 2^n)
// S.C = O(n + 2^n)  output + ans vector
class Solution {
private:
    void solve(vector<int>& nums, int i, vector<int>& output, vector<vector<int>>& ans) {
        if(i >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // take
        output.push_back(nums[i]);
        solve(nums, i+1, output, ans);
        output.pop_back();

        // now we have to avoid duplicates
        int idx = i+1;
        while(idx < nums.size() && nums[i] == nums[idx]) {
            idx++;
        }
        solve(nums, idx, output, ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums, 0, output, ans);
        return ans;
    }
};