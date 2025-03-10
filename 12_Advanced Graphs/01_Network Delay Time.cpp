// Question Link :- https://leetcode.com/problems/network-delay-time/
// Network Delay Time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        // vector<vector<pair<int, int>>> adj(n+1);
        for(auto &vec : times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v, w});   // directed graph
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});  // {d, src node}

        vector<int> result(n+1, INT_MAX);
        result[k] = 0;
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &vec : adj[node]) {
                int v = vec.first;
                int wt = vec.second;
                if(d + wt < result[v]) {
                    result[v] = d + wt;
                    pq.push({d+wt, v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, result[i]);
        }
	    return ans == INT_MAX ? -1 : ans;
    }
};