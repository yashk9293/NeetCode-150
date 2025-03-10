// Question Link :- https://leetcode.com/problems/minimum-window-substring/
// Minimum Window Substring (Hard)

//T.C : O(m+n) where m = length of s and n = length of t
//S.C : O(n)
class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size();
        if(m > s.size()) {
            return "";
        }
        vector<int> freq(256, 0);
        for(int i=0; i<m; i++) {
            freq[t[i]]++;
        }

        int cnt = 0, minLen = 1e9, startIdx = -1;
        int i = 0, j = 0;
        while(j < s.size()) {
            if(freq[s[j]] > 0) {
                cnt++;
            }
            freq[s[j]]--;
            while(cnt == m) {
                if(j-i+1 < minLen) {
                    minLen = j-i+1;
                    startIdx = i;
                }
                freq[s[i]]++;
                if(freq[s[i]] > 0) {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};
