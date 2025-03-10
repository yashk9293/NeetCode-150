// Question Link :- https://leetcode.com/problems/koko-eating-bananas/description/
// Koko Eating Bananas
// Using same concept "Leetcode 2187 (Minimum Time to Complete Trips)" [10]

// T.C = O(n log n)
// S.C = O(1)
class Solution {
public:
    bool canEatAll(vector<int>& piles, int mid, int h) {
        int currHour = 0;
        for(int &p : piles) {
            currHour += p/mid;
            if(p % mid != 0) {
                currHour++;
            }
        }
        return currHour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l < r) {
            int mid = l + (r-l)/2;
            if(canEatAll(piles, mid, h)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};