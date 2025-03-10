// Question Link :- https://leetcode.com/problems/insert-interval/
// Insert Interval


// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;

        int i = 0;

        // Left Part
        while(i<n && intervals[i][1] < newInterval[0] ){
            ans.push_back(intervals[i]);
            i++;
        }

        // Middle part
        while(i<n && intervals[i][0] <= newInterval[1] ){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);

        // Right Part
        while(i<n ){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};