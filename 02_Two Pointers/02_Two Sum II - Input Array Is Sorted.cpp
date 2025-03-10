// Question Link :- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Two Sum II - Input Array Is Sorted


// Brute Force
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target) {
                    return { i + 1, j + 1 };
                }
            }
        }
        return {};
    }
};



// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {
            int total = numbers[i] + numbers[j];
            if (total == target) {
                return {i + 1, j + 1};  // 1-indexed given in ques
            } else if (total < target) {
                i++;
            } else {
                j--;
            }
        }
        return {-1, -1}; // If no solution is found        
    }
};