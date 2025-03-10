// Question Link :- https://leetcode.com/problems/maximum-product-subarray/description/
// Maximum Product Subarray

// Brute Force
// T.C = O(n^3)
// S.C = O(1)
int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i; j<nums.size(); j++) {
            int prod = 1;
            for(int k=i; k<=j; k++) {
                prod *= nums[k];
            }
            result = max(result,prod);    
        }
    }
    return result;
}



// Brtue Force Optimised
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            int product = 1;
            for(int j=i; j<nums.size(); j++) {
                product *= nums[j];
                result = max(result, product);
            }
        }
        return result;
    }
};



// Optimal Solution (Kadane's Algorithm)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int prod = 1;

        for(int i=0; i<n; i++) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if(prod == 0) {
                prod = 1;
            }
        }
        prod = 1;
        for(int i=n-1; i>=0; i--) {
            prod *= nums[i];
            maxi = max(prod,maxi);
            if(prod == 0) {
                prod = 1;
            }
        }
        return maxi;
    }
};


// in 1 loop
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int leftProd = 1, rightProd = 1;

        for(int i=0; i<n; i++) {
            leftProd *= nums[i];
            rightProd *= nums[n-i-1];
            maxi = max({maxi, leftProd, rightProd});
            if(leftProd == 0) {
                leftProd = 1;
            }
            if(rightProd == 0) {
                rightProd = 1;
            }
        }
        return maxi;
    }
};