// Question Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
// Best Time to Buy and Sell Stock with Cooldown

// (buy/sell infinite no. of times, After you sell your stock, you cannot buy stock on the next day)

// Similar to Leetcode 122. Best Time to Buy and Sell Stock II

// Recursion
// T.C = O(2^n)
// S.C = O(n) -> recursion stack


// Memoization
// T.C = O(2n)  ->  There are N*2 states
// S.C = O(2n) + O(n)
class Solution {
public:
    int solve(int idx, bool buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        int profit;
        if(buy == 1) {
            // profit = max(take, skip);
            profit = max(-prices[idx] + solve(idx+1, 0, prices, dp), solve(idx+1, 1, prices, dp));
        } else {  // sell
            profit = max(prices[idx] + solve(idx+2, 1, prices, dp), solve(idx+1, 0, prices, dp));  // note : (idx+2) because after you sell your stock, you cannot buy stock on the next day
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};





// Tabulation
// T.C = O(2n)
// S.C = O(2n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));   // note : n+2, because for idx = n-1, dp[idx + 2] = dp[n-1+2] = dp[n+1].. so size should be (n+2)
        for (int idx = n-1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                if(buy) {
                    dp[idx][buy] = max(-prices[idx] + dp[idx + 1][0], dp[idx+ 1][1]);
                } else {
                    dp[idx][buy] = max(prices[idx] + dp[idx+ 2][1], dp[idx+ 1][0]);   // note : (idx+2) because after you sell your stock, you cannot buy stock on the next day
                }
            }
        }
        return dp[0][1];
    }
};