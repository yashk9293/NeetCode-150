// Question Link :- https://leetcode.com/problems/word-break
// Word Break


// Recursion
// T.C = O(n*2^n)
// S.C = O(m*k) + O(n)  [m = wordDict.size(), k = avg length of word in wordDict]
class Solution {
public:
    bool solve(int i, int n, string &s, unordered_set<string>& st) {
        if(i == n) {
            return true;
        }
        string temp;
        for(int j=i; j<n; j++) {
            temp += s[j];
            if(st.find(temp) != st.end() && solve(j+1, n, s, st)) {
                return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string> st;  // or set<string> st
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(0, n, s, st);
    }
};




// Memoization [35/47 tc passed]
// T.C = O(n^2)
// S.C = O(m*k) + O(n)  [m = wordDict.size(), k = avg length of word in wordDict]
class Solution {
public:
    bool solve(int i, int n, string &s, unordered_set<string>& st, vector<bool> t) {
        if(i == n) {
            return true;   // note - n tak ke saare strings wordDict me mil gye, isliye return true
        }
        if(t[i] != false) {
            return t[i];
        }
        string temp;
        for(int j=i; j<n; j++) {
            temp += s[j];
            if(st.find(temp) != st.end() && solve(j+1, n, s, st, t)) {
                return t[i] = true;
            }
        }
        return t[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> t(n+1, false);

        unordered_set<string> st;  // or set<string> st
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(0, n, s, st, t);
    }
};






// Tabulation
// T.C = O(n^2)
// S.C = O(m*k) + O(n)  [m = wordDict.size(), k = avg length of word in wordDict]
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> t(n+1, false);
        
        t[0] = true;  // string of length 0 is always true
        
        for(int i = 1; i<=n; i++) {
            //we choose different point (j) to break
            for(int j = 0; j<i; j++) {
                string temp = s.substr(j, i-j);
                
                if(st.count(temp) && t[j]) {  // it means from s[j...i] is in wordDict
                    t[i] = true; // t[j] = true means s[0...j] could also be broken correctly
                    break;
                }
            }
        }
        return t[n];  // length n
    }
};
    