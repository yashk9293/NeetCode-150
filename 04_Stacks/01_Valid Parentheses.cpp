// Question Link :- https://leetcode.com/problems/valid-parentheses/
// Valid Parentheses


// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '[' || ch == '{' || ch == '(') {
                st.push(ch);
            }
            else {
                char top = st.top();
                // for tc like "]", stack will be empty first so we need to check it
                if(st.empty() || (top == '[' && ch != ']') || 
                    (top == '{' && ch != '}') ||
                    (top == '(' && ch != ')')) {
                    return false;
                }
                st.pop();
            }
        }

        if(st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};