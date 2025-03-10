// Question Link :- https://leetcode.com/problems/longest-repeating-character-replacement/
// Longest Repeating Character Replacement

// Brute Force
// T.C = O(N^2)
// S.C = O(26) ~ O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        for(int i=0; i<s.length(); i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            
            for(int j=i; j<s.length(); j++) {
                freq[s[j]-'A']++;
                maxFreq = max(maxFreq, freq[s[j]-'A']);

                if((j-i+1) - maxFreq <=k) {   // length - maximum frequency <= k
                    maxLen = max(maxLen, j-i+1);
                } else {
                    break;
                }
            }
        }
        return maxLen;
    }
};





// Optimal Solution
// T.C = O(N + N) * 26 = O(N)
// S.C = O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int l = 0, r = 0;
        int maxFreq = 0;
        vector<int>freq(26, 0);
        while(r < s.length()) {
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r]-'A']);
            while((r-l+1) - maxFreq > k) {
                freq[s[l]-'A']--;
                maxFreq = max(maxFreq, freq[s[r]-'A']);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};




// Little bit optimised
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int l = 0, r = 0;
        int maxFreq = 0;
        vector<int>freq(26, 0);
        while(r < s.length()) {
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r]-'A']);
            if((r-l+1) - maxFreq > k) {        // modification 1 - if in place of while
                freq[s[l]-'A']--;
                maxFreq = max(maxFreq, freq[s[r]-'A']);
                l++;
            }
            if((r-l+1) - maxFreq <= k) {       // modification 2
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};