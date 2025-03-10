// Question Link :- https://www.geeksforgeeks.org/problems/alien-dictionary/1
// Alien Dictionary


// T.C = O(n*k + k+e) , (building graph + topo sort)
// S.C = O(K + E) ~ O(K^2) in the worst case
class Solution {
  public:
    string findOrder(vector<string> &words) {
        set<char> uniqueChars;
        for (const string &word : words) {
            for (char ch : word) {
                uniqueChars.insert(ch);
            }
        }
        int k = uniqueChars.size();

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            
			// for test cases like ["abc", "ab"]
            if (word1.size() > word2.size() && word1.substr(0, len) == word2) {
                return "";  
            }

            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    indegree[word2[j] - 'a']++;
                    break;
                }
            }
           
        }
        
        // Now topological sort BFS

        //2. Fill que, indegree with 0
        queue<int> q;
        for (char ch : uniqueChars) {
            if (indegree[ch - 'a'] == 0) {
                q.push(ch - 'a');
            }
        }
        //3. Simple BFS
        string result;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result += curr + 'a';

            for (auto v : adj[curr]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        // cout<<result<<endl;
        // agar result ka size set ke size se equal hua to wo valid hoga otherwise empty string return kr do
        return (result.size() == k) ? result : "";
    }
};



