// Question Link :- https://leetcode.com/problems/largest-rectangle-in-histogram/
// Largest Rectangle in Histogram

// Algorithm:
// 1. Find NSL Index array (nslIndex)
// 2. Find NSR Index array (nsrIndex)
// 3. Then width[i] = nsrIndex[i] - nslIndex[i] - 1
// 4. Then area[i] = histogram[i] * width[i]
// 5. Then mah = maximum element of 'area' array


// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    vector<int> _NSL(vector<int> &arr, int n) {
        stack<int> st;
        vector<int> v(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;
    }
    vector<int> _NSR(vector<int> &arr, int n) {
        stack<int> st;
        vector<int> v(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL = _NSL(heights, n);
        vector<int> NSR = _NSR(heights, n);

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int width = NSR[i] - NSL[i] - 1;
            ans = max(ans, width *(heights[i]));
        }
        return ans;
    }
};
