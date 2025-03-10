// Question Link :- https://leetcode.com/problems/combination-sum-ii/description/
// Combination Sum II


// Approach - 1 [TLE]
// Generating all subset and storing in set
// TC - 2^t x k x log(size of set)  , 2^t is for recursion and k is for copying the vectors and extra log tc because of set data structure
// S.C = O(n*2^n)
class Solution {
public:
	void solve(int i, vector<int> &arr, int target, vector<int> &output, set<vector<int>> &res) {
        if(target == 0) {
            res.insert(output);
            return;
        }

        if(i >= arr.size() || target < 0) {
            return;
        }
        // include
        output.push_back(arr[i]);
        solve(i+1, arr, target - arr[i], output, res);
        output.pop_back();

        // exclude
        solve(i+1, arr, target, output, res);
    }

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());    // sorted because we want output in lexicographically order

        set<vector<int>> res;
        vector<int> output;
        solve(0, candidates, target, output, res);

        vector<vector<int>> ans;
        for(auto &vec : res) {
			ans.push_back(vec);
		}
		return ans;
	}
};




// Approach - 2 (Using for loop)
// T.C = O(2^n*k)
// Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

// S.C = O(k*x)
// Reason: if we have x combinations then space will be x*k where k is the average length of the combination.

class Solution {
public:
	void solve(int idx, vector<int> &arr, int target, vector<int> &output, vector<vector<int>> &ans) {
		if (target == 0) {
			ans.push_back(output);
			return;
		}
        if(idx >= arr.size() || target < 0) {
            return;
        }

		for(int i = idx; i< arr.size(); i++) {
			if(i>idx && arr[i] == arr[i-1]) {
				continue;
			}
			output.push_back(arr[i]);
			solve(i+1, arr, target-arr[i], output, ans);
			output.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());    // sorted because we want output in lexicographically order
		vector<vector<int>> ans;
		vector<int> output;
		solve(0, candidates, target, output, ans);
		return ans;
	}
};