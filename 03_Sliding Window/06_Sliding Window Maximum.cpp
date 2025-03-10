// Question Link :- https://leetcode.com/problems/sliding-window-maximum/description/
// Sliding Window Maximum (Hard) (codestorywithMIK)

// Leetcode Question 1425 (Hard) same code


// Brute Force
// T.C = O(n*k)
for(i = 0-> n) {
    maxi = a[i]
    for(j = i -> i+k-1) {
        maxi= max(a[j], maxi)
    }
}




// This is generally known as "Monotonic increasing/decreasing  Queue/Dequeue"
// Every element is added(pushed) and popped only once,So it is O(N) time complexity.
// S.C = O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> result;
        for(int i = 0; i<n; i++) {
            //remove the max elements from front which are out of window size
            while(!deq.empty() && deq.front() <= i-k) {
                deq.pop_front();
            }
            //we maintain the deque in descending order
            while(!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i);

            if(i >= k-1) { //Only when the window size first gets equal or greater than k
                result.push_back(nums[deq.front()]); //front will have the max element (dequeue is maintained in descending order)
            }
        }
        return result;
    }
};