// Question Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// Best Time to Buy and Sell Stock

// (buy/sell only once)

// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        for (int i=0; i<n; i++) {
            int buy = prices[i];
            for (int j=i+1; j<n; j++) {
                int sell = prices[j];
                res = max(res, sell - buy);
            }
        }
        return res;
    }
};



// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = i+1;
        int maxProfit = 0;
        while(i<prices.size() && j<prices.size()) {
            if(prices[i] < prices[j]) {
                int ans = prices[j] - prices[i];
                maxProfit = max(maxProfit, ans);
            } else {
                i=j;
            }
            j++;
        }
        return maxProfit;
    }
};