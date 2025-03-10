// Question Link :- https://leetcode.com/problems/course-schedule-ii/
// Course Schedule II

// Simply the question is "Topological sort nikalo, aur check bhi karna cycle hai ya nhi in the directed graph"
// we have two method 
// i) BFS (Topological Sort[Kahn's Algorithm]) [08] - PREFERRED for this ques
// ii) DFS [07]


// Approach - 1 (BFS)
class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>> adj, int n, vector<int> indegree) {
        queue<int> q;
        vector<int> result;
        // Fill que, indegree with 0
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        // Simple BFS
	    while(!q.empty()) {
	        int u = q.front();
	        result.push_back(u);
	        q.pop();
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            if(indegree[v] == 0) {
	                q.push(v);
	            }
	        }
	    }
        if(result.size() == n) {
            return result;
        }
        return {};  // we had a cycle and we couln't complete all courses (couldn't visit all nodes)
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);  // b-->a
            indegree[a]++; // arrow ja raha hai 'a' me
        }
        return topologicalSort(adj, numCourses, indegree);
    }
};