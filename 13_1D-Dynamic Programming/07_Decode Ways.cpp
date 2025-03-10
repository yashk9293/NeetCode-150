// Question Link :- https://leetcode.com/problems/decode-ways/
// Decode Ways

// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int t[101];
    int solve(int i, string &s, int &n) {
        if(i == n) {
            return 1;  // one valid split done
        }

        if(s[i] == '0') {
            return 0;  // not possible to split
        }

        if(t[i] != -1) {
            return t[i];
        }

        int result = solve(i+1, s, n);
        
        if(i+1 < n) {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
                result += solve(i+2, s, n);
            }
        }
        return t[i] = result;
    }

    int numDecodings(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        return solve(0, s, n);
    }
};