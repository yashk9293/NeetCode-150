// Question Link :- https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Cheapest Flights Within K Stops

// Approach - 1 (Using BFS)
// T.C = O(V + E)
// S.C = O(V + E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(vector<int> &vec : flights) {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }
        
        queue<pair<int, int>> que;
        que.push({0, src});  // {dist, node}
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        
        int level = 0;
        
        while(!que.empty() && level <= k) {
            int N = que.size();
            while(N--) {   // current level ke saare nodes ko process karenge
                int d = que.front().first;
                int node = que.front().second;
                que.pop();
                for(auto &p : adj[node]) {
                    int v = p.first;
                    int wt = p.second;
                    
                    if(d + wt < distance[v]) {
                        distance[v] = d + wt;
                        que.push({d+wt, v});
                    }
                }
            }
            level++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};





// Approach - 2 (Using Dijkstra's Algorithm)
// T.C = O(M logM)
// S.C = O(N + M)
#define P pair<int, pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(vector<int> &vec : flights) {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{0, src}});  // {stops, {dist, node}}

        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        
        while(!pq.empty()) {
            int level = pq.top().first;
            int d = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            //note : (k+1)th stop is the destination stop after k stops from source
            //check if level exceeded k and the exceeded level node is not dest then skip
            if(level == k+1 && node != dst) {
                continue;
            }
            for(pair<int, int> &it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                if(d + wt < distance[v]) {
                    distance[v] = d + wt;
                    pq.push({level+1, {d+wt, v}});
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};