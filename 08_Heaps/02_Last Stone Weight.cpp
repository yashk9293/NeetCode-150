// Question Link :- https://leetcode.com/problems/last-stone-weight/
// Last Stone Weight


//Approach-1 (Brute Force) 
// TC = O(n^2 * log(n))
// S.C = O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1) {
            sort(stones.begin(), stones.end());

            int a = stones.back();
            stones.pop_back();
            int b = stones.back();
            stones.pop_back();

            stones.push_back(abs(a-b));
        }
        return stones[0];
    }     
};






//Approach-2 (Using Heap)
// TC = O(nlog(n))
// S.C = O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int x : stones) {
            maxHeap.push(x);
        }
        while(maxHeap.size() > 1) {
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            if(a != b) {
                maxHeap.push(abs(a-b));
            }
        }
        if(maxHeap.size()) {
            return maxHeap.top();
        }
        return 0;
    }
};