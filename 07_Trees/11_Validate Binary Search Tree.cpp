// Question Link :- https://leetcode.com/problems/validate-binary-search-tree
// Validate Binary Search Tree

// Approach - 1 (Inorder)
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    void solve(TreeNode* root, vector<int>&ans) {
        if(root == NULL) {
            return;
        }
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        for(int i=0; i<ans.size()-1; i++) {
            if(ans[i] >= ans[i+1]) {
                return false;
            }
        }
        return true;
    }
};




// Approach - 2 (Recursion)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    bool solve(TreeNode* root, long mini, long maxi) {
        if(root == NULL) {
            return true;
        }
        if(root->val <= mini || root->val >= maxi) {
            return false;
        }
        bool x = solve(root->left, mini, root->val);
        bool y = solve(root->right, root->val, maxi);
        return x && y;
    }

    bool isValidBST(TreeNode* root) {
        // key idea is to maintain range [INT_MIN,INT_MAX]; when any root->val is out of range return false
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};