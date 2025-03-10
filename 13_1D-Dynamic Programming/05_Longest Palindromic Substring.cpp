// Question Link :- https://leetcode.com/problems/longest-palindromic-substring/
// Longest Palindromic Substring


// Brute Force
// T.C = O(n^3)
// S.C = O(1)
class Solution {
public:
    bool checkPalindrome(string &s, int l, int r){
        while(l <= r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = INT_MIN;
        int startingIndex = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(checkPalindrome(s, i, j)) {
                    if(j-i+1 > maxlen){
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                } 
            }
        }
        return s.substr(startingIndex, maxlen);
    }
};







// NOTE :- for memoization we will use recursive check function to populate [t] matrix.


// Memoization will help reduce time complexity for cases like - "aaaaaaaaa"
// T.C = O(n^2) - Because the Amortized Time Complexity of checkPalindrome() will become 1 due to memoization.
// each substring's palindrome check takes constant time due to memoization.



// The checkPalindrome function is a recursive function with memoization. It checks if the substring s[l...r] is a palindrome.

// Without memoization, this function would have a complexity of O(n) per call since it compares characters while decreasing the range from both ends.

// However, since the results of subproblems are stored in the t table (memoization), each unique pair (l, r) is computed only once.

// The number of possible states (l, r) is O(n^2), so the total time complexity for this recursive function with memoization is O(n^2).

// Overall T.C = O(n^2) + O(n^2) ~ O(n^2)


// S.C = O(n^2)
class Solution {
public:
    int t[1001][1001];
    bool checkPalindrome(string &s, int l, int r) {
        if(l >= r) {
            return true;
        }
        if(t[l][r] != -1) {
            return t[l][r];
        }
        if(s[l] == s[r]) {
            return t[l][r] = checkPalindrome(s, l+1, r-1);
        }
        return t[l][r] = false;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int maxlen = INT_MIN;
        int startingIndex = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(checkPalindrome(s, i, j)) {
                    if(j-i+1 > maxlen){
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                } 
            }
        }
        return s.substr(startingIndex, maxlen);
    }
};





// Expand Around Center
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    string expandAroundCenter(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r-l-1);
    }

    string longestPalindrome(string s) {
        if(s.empty()) {
            return "";
        }
        string longest = "";

        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindrome (single character center)
            string odd = expandAroundCenter(s, i, i);
            if (odd.size() > longest.size()) {
                longest = odd;
            }
            // Even-length palindrome (two-character center)
            string even = expandAroundCenter(s, i, i + 1);
            if (even.size() > longest.size()) {
                longest = even;
            }
        }
        return longest;
    }
};