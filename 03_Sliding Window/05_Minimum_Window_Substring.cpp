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
        unordered_map<char, int> mpp;
        for(char &ch : t) {
            mpp[ch]++;
        }

        int cnt = 0, minLen = 1e9, startIdx = -1;
        int i = 0, j = 0;
        while(j < s.size()) {
            if(mpp[s[j]] > 0) {
                cnt++;
            }
            mpp[s[j]]--;
            while(cnt == m) {
                if(j-i+1 < minLen) {
                    minLen = j-i+1;
                    startIdx = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]] > 0) {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};

