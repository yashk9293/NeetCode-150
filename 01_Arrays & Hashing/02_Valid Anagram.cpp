// Question Link :- https://leetcode.com/problems/valid-anagram/description/
// Valid Anagram


// Approach 1
// T.C = O(nlogn) + O(n) = O(nlogn)
// S.C = O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};



// Approach 2
// T.C = O(n)
// S.C = O(26) ~ O(1) at max 26 characters can be stored in the map
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> mpp;

        for (char &ch : s) {
            mpp[ch]++;
        }

        for (char &ch : t) {
            mpp[ch]--;
        }

        for (auto& it : mpp) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }
};




// OR
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(s.size() != t.size()) {
            return false;
        }
        vector<int> count(26, 0);
        
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};