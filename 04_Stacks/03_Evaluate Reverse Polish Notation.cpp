// Question Link :- https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Evaluate Reverse Polish Notation


// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(auto x: tokens) {
            if(x  == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if(x == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if(x == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            }
            else if(x == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }
            else st.push(stoi(x));
        }
        return st.top();
    }
};