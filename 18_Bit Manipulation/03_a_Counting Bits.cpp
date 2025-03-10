// Question Link :- https://leetcode.com/problems/counting-bits
// Counting Bits

// T.C = O(nlogn)
// S.C = O(1)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0;i<=num;i++){
            int count = 0;
            int j = i;
            while(j!=0){
                count+=j%2;
                j/=2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};



// T.C = O(nlogn)
// S.C = O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        for(int i = 0; i<n+1; i++) {
            result[i] = __builtin_popcount(i); // log(n)
        }
        return result;
    }
};



// Follow Up question, do in O(n)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        result[0] = 0;
        for(int i = 1; i<=n; i++) {
            result[i] = result[i/2] + i%2;
        }
        return result;
    }
};