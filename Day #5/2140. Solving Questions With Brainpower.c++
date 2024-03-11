class Solution
{
    int n;
    long long help(vector<vector<int>> &questions, vector<long long> &dp, int ind)
    {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        long long take = help(questions, dp, ind + 1 + questions[ind][1]) + questions[ind][0];
        long long leave = help(questions, dp, ind + 1);

        return dp[ind] = max(take, leave);
    }

public:

// ----> MEMOIZATION APPROACH
    long long mostPoints(vector<vector<int>> &questions)
    {
        n = questions.size();
        vector<long long> dp(n, -1);
        return help(questions, dp, 0);
    }

// ----> BOTTOM-UP APPROACH 
    long long mostPoints(vector<vector<int>> &questions)
    {
        long long sol = 0;
        n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            long long take = questions[i][0] + dp[min(n, 1 + i + questions[i][1])];
            long long leave = dp[i + 1];
            dp[i] = max(take, leave);
        }

        return dp[0];
    }
};