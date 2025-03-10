// Question Link :- https://leetcode.com/problems/task-scheduler/description/
// Task Scheduler

// Approach - 1 (Using Heap)
// T.C = O(N*log(26)) = O(N) we have visited every task only once, that's why
// S.C = O(26) ~ O(1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(char &ch : tasks) {    // O(n)
            mp[ch-'A']++;
        }
        priority_queue<int> pq;
        for(auto &it : mp) {       // O(26)
            if(it>0) {
                pq.push(it);
            }
        }
        int time = 0;
        while(!pq.empty()) {
            vector<int> temp;
            // add n+1 element from pq to temp
            for(int i = 1; i<=n+1; i++) {
                if(!pq.empty()) {
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            // add the elements from temp back into the pq
            for(int &freq : temp) {
                if(freq > 0) {
                    pq.push(freq);
                }
            }
            // time
            if(pq.empty()) {
                time += temp.size();
            } else {
                time += (n+1);
            }
        }
        return time;
    }
};






// Approach - 2 (Using Greedy Algo)
// T.C = O(n) we have visited every task only once
// S.C = O(1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> mp(26,0);
        for(char &ch : tasks) {
            mp[ch-'A']++;
        }
        sort(begin(mp), end(mp)); // sorted in ascending so maximum freq element will be at last index
        
        int chunks = mp[25]-1;
        int idealSpots = chunks*n;
        // for rest of the element
        for(int i = 24; i>=0 ; i--) {
            idealSpots -= min(chunks, mp[i]);
        }
        if(idealSpots > 0) {
            return len + idealSpots;
        }
        return len;
    }
};