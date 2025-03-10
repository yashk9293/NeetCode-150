// Question Link :- https://leetcode.com/problems/rotting-oranges/description/
// Rotting Oranges

// We will not use DFS because we are travelling in levelwise (i.e. 4 directional adjacent), so 
// we will be using BFS Level order traversal.

// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0, fresh = 0;
        queue<pair<int, int>> q;   // (x, y)

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while(fresh > 0 && !q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int di = x + dx[i];
                    int dj = y + dy[i];

                    if (di >= 0 && dj >= 0 && di < n && dj < m && grid[di][dj] == 1) {
                        grid[di][dj] = 2; // Mark as rotten
                        q.push({di, dj});
                        fresh--;
                    }
                }
            }
            time++;
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (grid[i][j] == 1) {
        //             return -1;  // There are still fresh oranges
        //         }
        //     }
        // }
        // return time;

        return fresh == 0 ? time : -1;
    }
};