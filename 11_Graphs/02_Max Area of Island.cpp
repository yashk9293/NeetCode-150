// Question Link :- https://leetcode.com/problems/max-area-of-island
// Max Area of Island


// T.C = O(n*m) every cell is visited once
// S.C = O(n*m)
class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>>& visited, int &size) {
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || grid[i][j] != 1) {
            return;
        }
        
        visited[i][j] = true;
        size++;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int k=0; k<4; k++) {
            int di = i + dx[k];
            int dj = j + dy[k];
            dfs(di, dj, n, m, grid, visited, size);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int size = 0;
                    dfs(i, j, n, m, grid, visited, size);
                    ans = max(ans, size);
                }
            }
        }
        return ans;
    }
};
