class Solution
{
    vector<vector<int>> sol;
    int n;
    void help(vector<int> &nums, int s)
    {
        if (s >= n)
        {
            sol.emplace_back(nums);
            return;
        }

        for (int i = s; i < n; i++)
        {
            int temp = nums[s];
            nums[s] = nums[i];
            nums[i] = temp;
            help(nums, s + 1);
            temp = nums[s];
            nums[s] = nums[i];
            nums[i] = temp;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();

        help(nums, 0);
        return sol;
    }
};