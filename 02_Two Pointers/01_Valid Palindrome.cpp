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
        int i=0, j=s.length()-1;
        while(i<=j) {
            if(!isalnum(s[i])) {
                i++;
                continue;
            } else if(!isalnum(s[j])) {
                j--;
                continue;
            } else if(tolower(s[i]) == tolower(s[j])) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};