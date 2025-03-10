// Question Link :- https://leetcode.com/problems/hand-of-straights/
// Hand of Straights

// T.C = O(nlogn) + O(nlogn)
// S.C = O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) {
            return false;
        }
        map<int, int> mp;  // ordered_map - O(logn)
        for(int &num : hand) {
            mp[num]++; // O(nlogn)
        }
        while(!mp.empty()) { // O(n/groupSize)
            int curr = mp.begin()->first; //->second : frequency
            for(int i = 0; i < groupSize; i++) { // O(groupSize)
                if(mp[curr + i] == 0) {
                    return false;
                }
                mp[curr+i]--;
                if(mp[curr+i] == 0) {
                    mp.erase(curr+i);
                }
            }
        }
        return true;
    }
};