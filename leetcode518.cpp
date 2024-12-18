#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int helper(vector<int> coins, int amount, int n)
    {
        int dp[n + 1][amount + 1];
        for (int i = 0; i <= amount; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] >= j)
                {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount];
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        return helper(coins, amount, n);
    
    }
};