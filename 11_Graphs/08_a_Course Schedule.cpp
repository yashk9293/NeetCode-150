// Question Link :- https://leetcode.com/problems/course-schedule/
// Course Schedule (using BFS)

// Simply the question is "Detect cycle in directed graph"
// we have two method 
// i) BFS (Topological Sort[Kahn's Algorithm]) [09]
// ii) DFS [06]



// Approach - 1 (BFS - Kahn's Algorithm)
class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(int &v : adj[u]) { 
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }
        if(count == n) {  // I was able to visit all nodes (course)
            return true;  // i.e. I was able to finish all courses
        }
        return false;  // means there was a cycle and I couldn't complete all courses
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0); // kahn's algo
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);   // b ---> a
            indegree[a]++;  // arrow ja raha hai 'a' me
        }
        //if cycle is present, not possible
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};






// OR same Topological sort code
class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
        vector<int> result;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int u = que.front();
            result.push_back(u);
            que.pop();
            for(int &v : adj[u]) { 
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        if(result.size() == n) {  // I was able to visit all nodes (course)
            return true;  // i.e. I was able to finish all courses
        }
        return false;  // means there was a cycle and I couldn't complete all courses
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0); // kahn's algo
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);   // b ---> a
            indegree[a]++;  // arrow ja raha hai 'a' me
        }
        //if cycle is present, not possible
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};