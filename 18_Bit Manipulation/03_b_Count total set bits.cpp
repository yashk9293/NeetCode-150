// Question Link :- https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
// Count total set bits


// Approach - 1
// T.C = O(nlogn)
// S.C = O(1)
class Solution{
    public:
    int countSetBits(int n) {
        int cntBits = 0;
        for(int i=n; i>0; i--) {
            int value = i;
            while(value > 0) {
                if(value & 1) {    // value % 2 == 1
                    cntBits++;
                }
                value = value >> 1;     // value = value/2;
            }
        }
        return cntBits;
    }
};



// Approach - 2
// T.C = O(n)
// S.C = O(1)
class Solution{
    public:
    int countSetBits(int n) {
        vector<int> result(n+1);
        result[0] = 0;
        for(int i = 1; i<=n; i++) {
            result[i] = result[i/2] + i%2;
        }
        int cntBits = 0;
        for(auto &it : result) {
            cntBits += it;
        }
        return cntBits;
    }
};