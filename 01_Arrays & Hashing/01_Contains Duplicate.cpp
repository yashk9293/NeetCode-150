// Question Link :- https://leetcode.com/problems/contains-duplicate/
// Contains Duplicate


// Brute Force
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++) {
            for(int j=i+1;j<n; j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};



// Better Approach - 1
// T.C = O(nlogn)
// S.C = O(n)
// Set Approach
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(),nums.end());
        return n > st.size();
    }
};




// Better Approach - 2
// T.C = O(nlogn)
// S.C = O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};



// Optimal Approach
// T.C = O(n)
// S.C = O(n)
// Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) {
        mp[i]++;
        }
        for(auto i : mp){
            if(i.second >= 2) {
            return true;
            }
        }
        return false;
    }
};