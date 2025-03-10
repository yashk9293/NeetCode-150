// Question Link :- https://leetcode.com/problems/palindrome-partitioning
// Palindrome Partitioning

// T.C = O(n*2^n)
// S.C = O(n)

// The time complexity of the algorithm for generating all possible palindromic partitioning is typically expressed as
// O(n * 2^n), where n is the length of the input string. This complexity arises because there can be 2^n possible partitions,
// and for each partition, we need to check if each substring is a palindrome, which takes O(n) time in the worst case.


class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    void func(int index, vector<string> &path, string s, vector<vector<string>> &ans) {
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=index; i<s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                func(i+1, path, s, ans);     // Note: i+1
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0, path, s, ans);
        return ans;
    }
};