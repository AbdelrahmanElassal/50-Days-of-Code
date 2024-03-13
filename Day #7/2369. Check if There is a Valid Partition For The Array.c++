class Solution
{
    int n;
    bool help(vector<int> &nums, vector<int> &dp, int i)
    {
        if (i == n)
            return true;
        if (i == n - 1)
            return false;
        if (i == n - 2)
            return dp[i] = nums[i] == nums[i + 1];
        if (dp[i] != -1)
            return dp[i];

        bool three = false;
        bool two = false;

        if (nums[i] == nums[i + 1])
        {
            two = help(nums, dp, i + 2);
            if (nums[i] == nums[i + 2])
            {
                three = help(nums, dp, i + 3);
            }
        }
        if (nums[i] + 1 == nums[i + 1] && nums[i] + 2 == nums[i + 2])
        {
            three = help(nums, dp, i + 3);
        }

        return dp[i] = three || two;
    }

public:
    bool validPartition(vector<int> &nums)
    {
        n = nums.size();
        vector<int> dp(n, -1);
        return help(nums, dp, 0);
    }
};