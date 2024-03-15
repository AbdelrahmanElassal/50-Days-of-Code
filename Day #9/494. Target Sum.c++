class Solution
{
    map<pair<int, int>, int> dp;
    int help(vector<int> &nums, int &target, int sum, int i)
    {
        if (i >= nums.size())
        {
            return sum == target ? 1 : 0;
        }
        if (dp.count({i, sum}))
            return dp[{i, sum}];

        return dp[{i, sum}] = help(nums, target, sum + nums[i], i + 1) + help(nums, target, sum - nums[i], i + 1);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return help(nums, target, 0, 0);
    }
};