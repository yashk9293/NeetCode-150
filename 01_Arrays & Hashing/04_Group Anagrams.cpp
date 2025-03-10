// Question Link :- https://leetcode.com/problems/group-anagrams/
// Group Anagrams


// Approach 1: Using Sorting
// T.C = O(n*klogk)
// S.C = O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto str:strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        
        vector<vector<string>> result;
        for(auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};



// Approach 2: Using Frequency Array
// T.C = O(n*k)
// S.C = O(n*k)
class Solution {
public:
    string generate(string &s) {
        int freq[26] = {0};
        for(char &ch : s) {
            freq[ch-'a']++;
        }
        string new_s;
        for(int i = 0; i<26; i++) {
            if(freq[i] > 0) { // if  frequency of t is 3, then we have make "ttt"
                new_s += string(freq[i], i+'a');  // string(frequency, char)
            }
        }
        return new_s;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string &s : strs) {
            string new_s = generate(s);
            mp[new_s].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto &it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};