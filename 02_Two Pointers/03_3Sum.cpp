// Question Link :- https://leetcode.com/problems/3sum/description/
// 3Sum

// Brute Force
// T.C = O(n^3 * log(no. of unique triplets))
// S.C = O(2*(no. of triplets))
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        // check all possible triplets:
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());  // const, as only 3 elements
                        st.insert(temp);  // O(log(no. of unique triplets))
                    }
                }
            }
        }
        //store the set elements in the answer:
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};



// Better Approach : (Removing the 3rd for loop)
// T.C = O(n^2 * log(no. of unique triplets))
// S.C = O(2*(no. of triplets)) + O(n) -> mpp at max can store n elements
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            set<int> mpp;
            for (int j = i + 1; j < n; j++) {
                //Calculate the 3rd element:
                int third = -(nums[i] + nums[j]);

                //Find the element in the set:
                if (mpp.find(third) != mpp.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                mpp.insert(nums[j]);
            }
        }
        //store the set in the answer:
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};






// Optimal Approach : (Using Two Pointer Approach)
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));

        for(int i=0; i<n-2; i++) {
            //remove duplicates:
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i+1;
            int k = n-1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else if(nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    //skip the duplicates of j and k
                    while(j<k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};