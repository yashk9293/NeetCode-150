// Question Link :- https://leetcode.com/problems/powx-n/
// Pow(x, n)

// Something to learn : 
// Integer contains 32 bits, 1 bit is used for a sign flag (0 is + and 1 is -) and remaining 31 bits for values.
// For negative values we can express 2^31 different values (from -1 to -2^31) and for positive values 
// it is one value less since we still need to express zero.
// So, for positive we can express 2^31-1values with 31 bits, from 1 to 2^31-1. 
// That's why max negative and max positive do not match.
// So, if n=-2147483648 and we multiply n*-1, 
// We will get a number that is greater than Integer.MAX_VALUE as integer range is from -2147483648 to 2147483647
// That is why, we convert it to long.
// Hope you understood.



// Recursive Approach
// T.C = O(logN)
// S.C = O(logN)
class Solution {
public:
    double solve(double x, long n) { 
        if(n == 0) {
            return 1;
        }
        if(n < 0) {
            return solve(1/x, -n);
        }
        if(n%2 == 0) {
            return solve(x*x, n/2);
        }
        return x*solve(x*x, (n-1)/2);
    }
    double myPow(double x, int n) {
        return solve(x, (long)n);
    }
};






// Iterative Approach
// T.C = O(logN)
// S.C = O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        // long long N = labs(n);
        long long N = n;
        if(N < 0) {
            N = -N;
        }
        while(N > 0) {
            if(N%2 == 1){
                ans = ans * x;
                N--;
            } else {
                x = x*x;
                N /= 2;
            }
        }
        if(n < 0){
            ans = 1.0/ans;
        }
        return ans;
    }
};