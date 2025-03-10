// Question Link :- https://leetcode.com/problems/trapping-rain-water/
// 42. Trapping Rain Water (Aditya Verma)

// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ngl[n] , ngr[n];

        ngl[0] = height[0];
        for(int i=1; i<n; i++){
            ngl[i] =  max(ngl[i-1], height[i]);
        }

        ngr[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            ngr[i] = max(ngr[i+1], height[i]);
        }

        int water[n]; 
        for(int i=0; i<n; i++){
            water[i] = min(ngl[i], ngr[i]) - height[i];
        }
        int sum =0;
        for(int i=0; i<n; i++){
            sum += water[i];
        }
        return sum;
    }
};