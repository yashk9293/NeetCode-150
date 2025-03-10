// Question Link :- https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Maximum Depth of Binary Tree

// T.C = O(N)
// S.C = O(N) 
// where N is the number of nodes in the Binary Tree because in the worst case scenario 
// the tree is balanced and has N/2 nodes in its last level which will have to be stored in the queue.

class Solution {
public:
    int solve(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);

        return 1 + max(l,r);
    }

    int maxDepth(TreeNode* root) {
        return solve(root); 
    }
};




class Solution {
public:
    int maxDepth(TreeNode* root) {
        int cnt = 0;
        if(root == NULL) {
            return cnt;
        }

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            cnt++;
        }
        return cnt;
    }
};