// Question Link :- https://leetcode.com/problems/trapping-rain-water/
// 42. Trapping Rain Water (Striver)

// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int res = 0;
        int maxleft = height[l], maxright = height[r];

        while(l < r) {
            if(maxleft < maxright) {
                l++;
                maxleft = max(maxleft, height[l]);
                res += maxleft - height[l];
            }
            else {      // (height[l] > height[r])
                r--;
                maxright = max(maxright, height[r]);
                res += maxright - height[r];
            }
        }
        return res;
    }
};