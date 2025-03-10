// Question Link :- https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Kth Largest Element in a Stream

// Brute Force (TLE)
// T.C = O(n logn)
// S.C = O(n)
class KthLargest {
public:
    int K = 0;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        v = nums;
    }
    
    int add(int val) {
        v.push_back(val);
        sort(rbegin(v), rend(v));

        return v[K-1];
    }
};






// Optimal Approach
// T.C = O(n logk)
// S.C = O(n)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};