class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> sol;
        for (auto &it : nums)
        {
            while (nums[it - 1] != it)
            {
                swap(it, nums[it - 1]);
            }
        }

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                sol.emplace_back(nums[i]);
        return sol;
    }
};