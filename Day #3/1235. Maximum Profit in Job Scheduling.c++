class Solution
{
    //--> Recursive Solution
    int help(vector<vector<int>> &tasks, vector<int> &startTime, vector<int> &dp, int in)
    {
        if (in >= tasks.size())
            return 0;
        if (dp[in] != -1)
            return dp[in];

        int next = lower_bound(startTime.begin(), startTime.end(), tasks[in][1]) - startTime.begin();
        int wcurr = tasks[in][2] + help(tasks, startTime, dp, next);
        int woucurr = help(tasks, startTime, dp, in + 1);
        return dp[in] = max(woucurr, wcurr);
    }

public:
    int jobSchedulingRecursive(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<vector<int>> tasks(profit.size(), vector<int>(3));
        vector<int> dp(profit.size(), -1);
        for (int i = 0; i < profit.size(); i++)
        {
            tasks[i][0] = startTime[i];
            tasks[i][1] = endTime[i];
            tasks[i][2] = profit[i];
        }
        sort(tasks.begin(), tasks.end());
        sort(startTime.begin(), startTime.end());

        return help(tasks, startTime, dp, 0);
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

//--> Iterative Solution
    int jobSchedulingIterative(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<vector<int>> tasks(profit.size(), vector<int>(3));
        vector<int> dp(profit.size() + 1, 0);
        for (int i = 0; i < profit.size(); i++)
        {
            tasks[i][0] = startTime[i];
            tasks[i][1] = endTime[i];
            tasks[i][2] = profit[i];
        }
        sort(tasks.begin(), tasks.end());
        sort(startTime.begin(), startTime.end());

        for (int i = profit.size() - 1; i >= 0; i--)
        {
            int woucurr = dp[i + 1];
            int next = lower_bound(startTime.begin(), startTime.end(), tasks[i][1]) - startTime.begin();
            int wcurr = tasks[i][2] + dp[next];
            dp[i] = max(woucurr, wcurr);
        }

        return dp[0];
    }
};


