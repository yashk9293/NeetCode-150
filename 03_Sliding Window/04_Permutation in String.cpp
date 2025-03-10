// Question Link :- https://leetcode.com/problems/permutation-in-string
// Permutation in String


// Brute Force (generate all permutations of s1 and check in s2) [TLE]
// T.C = O(n! * s2.length()) (n! for permutations and s2.length() for checking in s2)
// S.C = O(n)
class Solution {
public:
    void solve(int idx, string& s1, string& s2, bool& result) {
        if (idx == s1.length()) {
            if (s2.find(s1) != string::npos) {
                result = true;
            }
            return;
        }

        for (int i = idx; i < s1.length(); i++) {
            swap(s1[i], s1[idx]);
            solve(idx + 1, s1, s2, result);
            swap(s1[i], s1[idx]);
        }
    }

    bool checkInclusion(string s1, string s2) {
        bool result = false;
        solve(0, s1, s2, result);
        return result;
    }
};




// Better Approach
// T.C = O(m-n * nlogn)
// S.C = O(n)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) {
            return false;
        }
        // Sort the string s1
        sort(s1.begin(), s1.end());

        // Iterate over each substring of s2 of length equal to s1
        for (int i = 0; i <= m - n; i++) {
            // Extract a substring of length n from s2 starting at index i
            string temp = s2.substr(i, n);

            // Sort the substring
            sort(temp.begin(), temp.end());

            // If the sorted substring matches the sorted s1, return true
            if (temp == s1) {
                return true;
            }
        }
        return false;
    }
};




// Sliding Window
// T.C = O(m+n)
// S.C = O(26)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) {
            return false;
        }
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        for(auto ch: s1) {
            vec1[ch-'a']++;
        }
        int i = 0;
        for(int j=0; j<s2.size(); j++) {
            vec2[s2[j]-'a']++;
            if(j-i+1 > s1.size()) {
                vec2[s2[i]-'a']--;
                i++;
            }
            // Check if the current window's frequency matches s1's frequency
            if (vec1 == vec2) {
                return true;
            }
        }
        return false;
    }
};