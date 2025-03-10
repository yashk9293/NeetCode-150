// Question Link :- https://leetcode.com/problems/number-of-islands/
// Number of Islands

// Approach - 1 (DFS)
// T.C = O(m*n)
// S.C = O(m*n)
class Solution {
public:
    vector<pair<int, int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i<0 || i>= grid.size() || j<0 || j>= grid[0].size() || visited[i][j] || grid[i][j] != '1') {
            return;
        }
        visited[i][j] = true;
        for(pair<int, int>& p : dir) {
            int di = i + p.first;
            int dj = j + p.second;
            dfs(grid, di, dj, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};







// Approach - 2 (BFS)
// T.C = O(m*n)
// S.C = O(m*n)
class Solution {
public:
    vector<pair<int, int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        queue<pair<int, int>> que;
        que.push({i, j});
        visited[i][j] = true;
        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(auto &p : dir) {
                int di = x  + p.first;
                int dj = y + p.second;
                if(di>=0 && di< grid.size() && dj>=0 && dj< grid[0].size() && grid[di][dj] == '1' && visited[di][dj] == false) {
                    que.push({di, dj});
                    visited[di][dj] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};