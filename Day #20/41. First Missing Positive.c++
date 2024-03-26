class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        for (auto &it : nums)
        {
            while (it > 0 && it < nums.size() && it != nums[it - 1])
            {
                swap(it, nums[it - 1]);
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return nums.size() + 1;
    }
};