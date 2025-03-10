// Question Link :- https://leetcode.com/problems/reverse-integer/description/
// Reverse Integer

// T.C = O(d) ~ O(1) where d is the number of digits in the input number
// S.C = O(1)
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0) {
            int digit = x%10;
            if((ans > INT_MAX/10) || (ans < INT_MIN/10)) {
                return 0;
            }
            ans = (ans*10) + digit;
            x = x/10;
        }
        return ans;
    }
};


// Since the maximum value of x is 2^31 - 1 (which has at most 10 digits), d ≤ 10