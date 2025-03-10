// Question Link :- https://leetcode.com/problems/number-of-1-bits/description/
// Number of 1 Bits

// T.C = O(logn)
// S.C = O(1)
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n) {
            count += (n%2);
            n = n/ 2;
        }
        return count;
    }
};




// Brian Kernighan’s Algorithm
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            count++;
            n &= (n - 1);  // Clears the rightmost set bit
        }
        return count;
    }
};