//O(N) Time // O(1) Space

//SOL 1
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> sol;
        for (auto &it : nums)
        {
            int i = abs(it) - 1;
            nums[i] = abs(nums[i]) * -1;
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                sol.emplace_back(i + 1);

        return sol;
    }
};

//SOL 2
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
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
                sol.emplace_back(i + 1);
        return sol;
    }
};