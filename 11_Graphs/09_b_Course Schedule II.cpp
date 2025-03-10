// Question Link :- https://leetcode.com/problems/course-schedule-ii/
// Course Schedule II

// Simply the question is "Topological sort nikalo, aur check bhi karna cycle hai ya nhi in the directed graph"
// we have two method 
// i) BFS (Topological Sort[Kahn's Algorithm]) [08]
// ii) DFS [07]


// Approach - 2 (DFS)
// * Directed graph, cycle --> inRecursion
// * Topological Sort

class Solution {
public:
    bool hasCycle = false;
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {
	    visited[u] = true;
        inRecursion[u] = true;
	    // pehle mere ('u' ke node ke ) bachho ko daalo
	    for(int &v : adj[u]) {
            if(inRecursion[v] == true) {
                hasCycle = true;
                return;
            }
	        if(!visited[v]) {
	            DFS(adj, v, visited, st, inRecursion);
            }
	    }
	    // ab mujhe daalo stack me
	    st.push(u);
        inRecursion[u] = false;
	}
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        hasCycle = false;
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            // b--->a
            adj[b].push_back(a);
        }
        stack<int> st;
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i]) {
                DFS(adj, i, visited, st, inRecursion);
            }
        }
        if(hasCycle) {
            return {};
        }
        vector<int> result;
	    while(!st.empty()) {
	        result.push_back(st.top());
	        st.pop();
	    }
	    return result;
    }
};