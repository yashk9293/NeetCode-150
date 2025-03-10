// Question Link - https://leetcode.com/problems/merge-intervals/description/
// Merge Intervals


// Brute Force
// T.C = O(nlogn) + O(n^2)
// S.C = O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!ans.empty() && end <= ans.back()[1]) {
                continue;
            }

            for(int j = i+1; j<n; j++) {
                if(intervals[j][0] <= end) {
                    end = max(intervals[j][1],end);
                }
                else {
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};





// Optimal Solution - 1 (Line Sweep Algorithm)
// T.C = O(nlogn)
// S.C = O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<pair<int, int>> line_sweep;

        for(auto &vec : intervals) {
            line_sweep.push_back({vec[0], 1});
            line_sweep.push_back({vec[1], -1});
        }

        auto lambda = [&](pair<int, int>&a, pair<int, int>& b) {
            if(a.first == b.first) {   // If a.first and b.first is the same, prioritize +1 over -1, such that +1 comes first then -1. This ensures that intervals starting at the same point are handled first before any closing event.
                return a.second > b.second;
            }
            return a.first < b.first;
        };

        sort(begin(line_sweep), end(line_sweep), lambda);

        int cnt = 0;
        int start = 0;
        for(const auto& it : line_sweep) {
            int x = it.first;
            int type = it.second;

            if(cnt == 0 && type == 1) {
                start = x;
            }
            cnt += type;

            if(cnt == 0) {
                ans.push_back({start, x});
            }
        }
        return ans;
    }
};






// Optimal Solution - 2
// T.C = O(nlogn)
// S.C = O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            // if the current interval does not lie in the last interval:
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            // if the current interval lies in the last interval:
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};