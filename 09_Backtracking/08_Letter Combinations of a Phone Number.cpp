// Question Link :- https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Letter Combinations of a Phone Number


// T.C. = O(4^n) worst case or O(3^n) in average case.
// Each digit maps to 3 or 4 possible letters.
// S.C. = O(4^n + n)
class Solution {
public:
    void solve(int idx, string digits, string output,vector<string>& ans, string mapping[] ) {
        if(idx >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[idx] - '0';
        string value = mapping[number];
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(idx+1, digits, output, ans, mapping);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) {
            return ans;
        }
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(0, digits, output, ans, mapping);
        return ans;
    }
};



// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


// Input: digits = ""
// Output: []


// Input: digits = "2"
// Output: ["a","b","c"]