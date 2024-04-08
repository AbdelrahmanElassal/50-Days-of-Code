class Solution
{
    int n;
    int help(vector<int> &prices, int i, bool se, vector<vector<int>> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[(int)se][i] != INT_MIN)
            return dp[(int)se][i];
        int prof = INT_MIN;
        if (se)
        {
            prof = max(help(prices, i + 1, !se, dp) - prices[i], help(prices, i + 1, se, dp));
            dp[(int)se][i] = prof;
        }
        else
        {
            prof = max(help(prices, i + 2, !se, dp) + prices[i], help(prices, i + 1, se, dp));
            dp[(int)se][i] = prof;
        }
        return prof;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, INT_MIN));
        return help(prices, 0, true, dp);
    }
};