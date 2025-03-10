// Question Link :- https://leetcode.com/problems/generate-parentheses/
// Generate Parentheses

// Approach - 1
// T.C = O(2^2n * 2n) -> 2^2n is taking or not taking the 2*n brackets, and 2n is for checking if it is valid or not.
// S.C = O(2n) [depth of recursion tree = 2n]
class Solution {
public:
    bool isValid(string str) {
        int count = 0;
        for(char &ch : str) {
            if(ch == '(') {
                count++;
            } else {
                count--;
            }
            if(count < 0) {
                return false;
            }
        }
        return count == 0;
    }
    void solve(int n, string& str, vector<string>& result) {
        if(str.size() == 2*n) {
            if(isValid(str)) {
                result.push_back(str);
            }
            return;
        }
        str.push_back('(');
        solve(n, str, result);
        str.pop_back();

        str.push_back(')');
        solve(n, str, result);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str = "";
        solve(n, str, result);
        return result;
    }
};






// Approach - 2
// here we do not need isValid func, as we are using 2 checks, that is (open<n) and (close<open)
// so we will always get valid parentheses.
// T.C = O(2^2n)
// S.C = O(2n)
class Solution {
public:
    void solve(int n, string& str, vector<string>& result, int open, int close) {
        if(str.size() == 2*n) {
            result.push_back(str);
            return;
        }
        if(open < n) {
            str.push_back('(');
            solve(n, str, result, open+1, close);
            str.pop_back();
        }
        if(close < open) {
            str.push_back(')');
            solve(n, str, result, open, close+1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str = "";
        solve(n, str, result, 0, 0);
        return result;
    }
};