// Question Link : - https://leetcode.com/problems/combination-sum/
// Combination Sum (striver sheet)

// T.C = O(2^t * k) where t is the target, k is the average length
// Reason: Assume if you were not allowed to pick a single element multiple times, every element 
// will have a couple of options: pick or not pick which is 2^n different recursion calls, also 
// assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

// Why not (2^n) but (2^t) (where n is the size of an array)?

// Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

// S.C: O(k*x), k is the average length and x is the no. of combinations



class Solution {
    public:
    void solve(int i, vector<int> &arr, int target, vector<int> &output, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(output);
            return;
        }

        if(i >= arr.size() || target < 0) {
            return;
        }
        // include
        output.push_back(arr[i]);
        solve(i, arr, target - arr[i], output, ans); // stay at same index, as we can take same no. multiple times
        output.pop_back();

        // exclude
        solve(i+1, arr, target, output, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, candidates, target, output, ans);
        return ans;
    }
};



// TC - 2^t x k