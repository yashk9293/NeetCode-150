// Question Link - https://www.codingninjas.com/studio/problems/reading_6845742
// Two Sum (Return YES or NO)

// Brute Force
// T.C = O(N^2)
// S.C = O(1)
string read(int n, vector<int> arr, int target) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == target) {
                return "YES";
            }
        }
    }
    return "NO";
}



// Better Approach
// T.C = O(N)
// S.C = O(N)
string read(int n, vector<int> arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}





// Optimal Solution
// T.C = O(n logn)
// S.C = O(1)
string read(int n, vector<int> arr, int target){
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size()-1;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) {
            return "YES";
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return "NO";
}