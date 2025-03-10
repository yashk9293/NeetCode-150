// Question Link :- https://neetcode.io/problems/meeting-schedule
// Meeting Rooms


// T.C = O(nlogn) + O(n) = O(nlogn)
// S.C = O(1)
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) { 
            return x.start < y.start; 
        });

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};