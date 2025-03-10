// Question Link :- https://leetcode.com/problems/word-search/
// Word Search

// T.C = O(N * M * 4^L)
// here L is the length of the word. And we are searching for the letter N*M times in the worst case. 
// Here 4 in 4^K is because at each level of our decision tree we are making 4 recursive calls which equal 4^K in the worst case.
// S.C = O(L) due to recursion stack
class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool solve(int i, int j, int m, int n, string &str, vector<vector<bool>>& visited, vector<vector<char>>& board, string &word) {
        if(str == word) {
            return true;
        }
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || str.size() > word.size()) {
            return false;
        }

        str += board[i][j];
        visited[i][j] = true;
        
        for(auto& dir : directions) {
            int di = i + dir[0];
            int dj = j + dir[1]; 
            if(solve(di, dj, m, n, str, visited, board, word)) {
                return true;
            }
        }
        str.pop_back();
        visited[i][j] = false;

        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(m*n < word.length()) {
            return false;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if (!visited[i][j] && board[i][j] == word[0]) {  
                    string s = "";
                    if (solve(i, j, m, n, s, visited, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
