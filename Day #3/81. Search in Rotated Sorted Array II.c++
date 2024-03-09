class Solution
{
    bool binarySearch(vector<int> &nums, int l, int r, int target)
    {
        while (r >= l)
        {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return true;

            else if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return false;
    }

public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
            return nums[0] == target;
        if (nums.size() == 2)
            return (nums[0] == target || nums[1] == target);
        int k = 1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] == target)
                return true;
            if (nums[i] < nums[i - 1])
                break;
            k++;
        }
        if (k == nums.size())
            k = 0;
        bool isthere = false;
        if (nums[0] < target)
        {
            isthere = binarySearch(nums, 0, nums.size() - 1 - k, target);
        }
        else if (nums[0] > target)
        {
            isthere = binarySearch(nums, nums.size() - k, nums.size() - 1, target);
        }

        else
            return true;

        return isthere;
    }
};