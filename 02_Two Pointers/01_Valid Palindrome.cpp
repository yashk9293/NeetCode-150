// Question Link :- https://leetcode.com/problems/valid-palindrome/
// Valid Palindrome


// Approach 1
// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for (char ch : s) {
            if (isalnum(ch)) {
                newStr += tolower(ch);
            }
        }
        return newStr == string(newStr.rbegin(), newStr.rend());
    }
};



// Approach 2
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start <= end) {
            while (start < end && !isalnum(s[start])) {
                start++;
            }
            while (start < end && !isalnum(s[end])) {
                end--;
            }
            if(tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};