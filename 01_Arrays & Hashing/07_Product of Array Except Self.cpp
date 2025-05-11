// Question Link :- https://leetcode.com/problems/product-of-array-except-self/
// Product of Array Except Self


// Brute Force
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            int prod = 1;
            for(int j=0; j<n; j++) {
                if(i == j) {
                    continue;
                }
                prod *= nums[j];
            }
            ans.push_back(prod);
        }
        return ans;
    }
};



// Optimized Approach
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int prod = 1;
        int cnt_zero = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                prod *= nums[i];
            } else {
                cnt_zero++;
            }
        }
        if(cnt_zero == 0) {
            for(int i=0; i<n; i++) {
                ans[i] = prod/nums[i];
            }
        }
        if(cnt_zero == 1) {
            for(int i=0; i<n; i++) {
                if(nums[i] == 0) {
                    ans[i] = prod;
                }
            }
        }
        return ans;  // if cnt_zero >= 2 then simply return null vector
    }
};





// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1, cnt_zero = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                prod *= nums[i];
            } else {
                cnt_zero++;
            }
        }
        if(cnt_zero == 0) {
            for(int i=0; i<n; i++) {
                nums[i] = prod/nums[i];
            }
        }
        if(cnt_zero == 1) {
            for(int i=0; i<n; i++) {
                if(nums[i] == 0) {
                    nums[i] = prod;
                } else {
                    nums[i] = 0;
                }
            }
        }
        if(cnt_zero >= 2) {
            // for(int i=0; i<n; i++) {
            //     nums[i] = 0;
            // }
            fill(nums.begin(), nums.end(), 0);
        }
        return nums;
    }
};



// Optimal Solution (Without using division)
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n, 1);
        for(int i=1; i<n; i++) {
            pref[i] = nums[i-1]*pref[i-1];
        }

        vector<int> suff(n, 1);
        for(int i=n-2; i>=0; i--) {
            suff[i] = nums[i+1] * suff[i+1];
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = pref[i] * suff[i];
        }
        return ans;
    }
};


// https://youtu.be/TW2m8m_FNJE
// Optimal Solution (Without using division)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // Prefix product
        for (int i=1; i<n; i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        
        // Suffix product
        int suff = 1;
        for (int i = n-2; i >= 0; i--) {
            suff *= nums[i+1];
            res[i] *= suff;
        }
        return res;
    }
};