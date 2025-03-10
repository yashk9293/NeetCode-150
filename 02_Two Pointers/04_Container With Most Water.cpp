// Question Link :- https://leetcode.com/problems/container-with-most-water/
// Container With Most Water


// Brute Force Approach
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = min(heights[i], heights[j]) * (j - i);
                res = max(res, area);
            }
        }
        return res;
    }
};



// Optimal Approach
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxArea = 0;
        while(i < j) {
            int w = j - i;
            int h = min(height[i], height[j]);
            int area = w * h;
            maxArea = max(maxArea, area);

            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};