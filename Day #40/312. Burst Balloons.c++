class Solution
{
    int help(vector<int> &nums, vector<vector<int>> &dp, int l, int r)
    {
        if (r < l)
            return 0;
        if (dp[l][r])
            return dp[l][r];

        int sol = 0;
        for (int i = l; i <= r; i++)
        {
            int curr = nums[i] * nums[l - 1] * nums[r + 1];
            curr += (help(nums, dp, l, i - 1) + help(nums, dp, i + 1, r));
            sol = max(sol, curr);
        }

        return dp[l][r] = sol;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        return help(nums, dp, 1, n - 2);
    }
};