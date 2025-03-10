// Question Link - https://leetcode.com/problems/rotate-image/
// Rotate Image

// Brute Force
// T.C = O(N^2)
// S.C = O(N^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int> (n, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                rotated[j][n-i-1] = matrix[i][j];
            }
        }
        matrix = rotated;
    }
};



// T.C = O(N^2)
// S.C = O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        for(int i =0; i<matrix.size();i++){
            for(int j =0 ; j<i ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};