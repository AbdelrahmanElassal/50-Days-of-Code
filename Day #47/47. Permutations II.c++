class Solution
{
    int n;
    void help(vector<int> nums, vector<vector<int>> &sol, int i)
    {
        if (i == n - 1)
        {
            sol.push_back(nums);
            return;
        }
        for (int ind = i; ind < n; ind++)
        {
            if (i != ind && nums[i] == nums[ind])
                continue;
            swap(nums[i], nums[ind]);
            help(nums, sol, i + 1);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<vector<int>> sol;
        help(nums, sol, 0);
        return sol;
    }
};