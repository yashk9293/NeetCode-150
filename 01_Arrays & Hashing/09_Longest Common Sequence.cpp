// Question Link - https://leetcode.com/problems/longest-consecutive-sequence/
// Longest Common Sequence

// Method - 1
// T.C = O(NlogN) + O(N)
// S.C = O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int longest = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {   // Skip duplicates
                continue;
            }
            if (nums[i] == nums[i - 1] + 1) {
                cnt++;
            } else {
                longest = max(longest, cnt);
                cnt = 1;  // Reset count
            }
        }
        return max(longest, cnt);
    }
};






// Method - 2
// T.C = O(N) + O(2N) ~ O(3N)
// S.C = O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            //if 'it' is a starting number:
            if (st.find(it - 1) == st.end()) {
                //find consecutive numbers:
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};