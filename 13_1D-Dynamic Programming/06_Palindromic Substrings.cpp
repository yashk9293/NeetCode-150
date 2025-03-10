// Question Link :- https://leetcode.com/problems/palindromic-substrings/
// Palindromic Substrings


// Brute Force
// T.C = O(n^3)
// S.C = O(1)
class Solution {
public:
    bool check(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }
        if(s[i] == s[j]) {
            return check(s, i+1, j-1);
        }
        return false;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) { // check all possible substrings
                if(check(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};



// Memoize
// T.C = O(n^2)
// S.C = O(n^2)
class Solution {
public:
    int t[1001][1001];
    bool check(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }
        if(t[i][j] != -1) {
            return t[i][j];
        }
        if(s[i] == s[j]) {
            return t[i][j] = check(s, i+1, j-1);
        }
        return t[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) { // check all possible substrings
                if(check(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};





// Expand Around Center
// T.C = O(n^2)  because for a character worst case can be to traverse all neighbours.
// S.C = O(1)
class Solution {
public:
    int expandAroundCenter(string s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            cnt++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindrome (single character center)
            int odd = expandAroundCenter(s, i, i);

            // Even-length palindrome (two-character center)
            int even = expandAroundCenter(s, i, i + 1);
            
            ans += odd + even;
        }
        return ans;
    }
};