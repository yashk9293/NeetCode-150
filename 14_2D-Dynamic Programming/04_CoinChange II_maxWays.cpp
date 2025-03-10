// Question Link :- https://leetcode.com/problems/coin-change-ii/description/
// Coin Change max no. of ways (Coin Change II)

// Similar to [06_count of subset with given sum.cpp]

// T.C = O(n*amount)
// S.C = O(n)

// Approach - 1 (Recursion + Memoization)

class Solution {
public:
    int t[301][5001];
    int solve(vector<int>& coins, int n, int amount) {
        if(n == 0) {
            if(amount == 0) {
                return 1;
            }
            return 0;
        }

        if(t[n][amount] != -1) {
            return t[n][amount];
        }
        
        if(coins[n-1] <= amount) {
            t[n][amount] = solve(coins, n, amount-coins[n-1]) + solve(coins, n-1, amount);
        } else {
            t[n][amount] = solve(coins, n-1, amount);
        }

        return t[n][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(t, -1, sizeof(t));

        return solve(coins, n, amount);
    }
};







// Approach - 2 (Tabulation)
// aditya verma
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int t[n + 1][amount + 1];
    	// initialization
    	for (int i = 0; i <= n; i++) {
    		for (int j = 0; j <= amount; j++) {
    			if (i == 0) {
    				t[i][j] = 0;
    			}
    			if (j == 0) {
    				t[i][j] = 1;
    			}
    		}
    	}
    
    	for (int i = 1; i <= n; i++) {
    		for (int j = 0; j <= amount; j++) {  // NOTE :- here j started from 0
    			if (coins[i - 1] <= j) {
    				t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];    // max ways
    			} else {
    				t[i][j] = t[i - 1][j];
    			}
    		}
    	}
    	return t[n][amount];
    }
};