// Question Link :- https://neetcode.io/problems/count-connected-components
// Number of Connected Components in an Undirected Graph

// Approach - 1 (DFS)
// T.C = O(V+E)
// S.C = O(V+E)
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;
        for(int v : adj[u]) {
            if(!visited[v]) {
                dfs(v, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited);
                cnt++;
            }
        }
        return cnt;
    }
};




// Approach - 2 (BFS)
// T.C = O(V+E)
// S.C = O(V+E)
class Solution {
public:
    void bfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            for(int v : adj[curr]) {
                if(!visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                bfs(i, adj, visited);
                cnt++;
            }
        }
        return cnt;
    }
};
    