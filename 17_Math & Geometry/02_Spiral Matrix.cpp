// Question Links :- https://leetcode.com/problems/spiral-matrix
// Spiral Matrix


// T.C = O(n*m)  The algorithm visits each element exactly once.
// S.C = O(1) auxiliary space
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int top = 0, left = 0, bottom = n - 1, right = m - 1;
        int direction = 1;

        while (top <= bottom && left <= right) {   // loop until all elements are not traversed
            if(direction == 1 ) {// For moving left to right
                for (int i=left; i<=right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                direction = 2;
                top++;
            }

            else if(direction == 2) {  // For moving top to bottom.
                for (int i=top; i<=bottom; i++) {
                    ans.push_back(matrix[i][right]);
                }
                direction = 3;
                right--;
            }
            
            else if(direction == 3) {   /// // For moving right to left.
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                direction = 4;
                bottom--;
            }

            else if(direction == 4) {   // // For moving bottom to top.
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                direction = 1;
                left++;
            }
        }
        return ans;
    }
};