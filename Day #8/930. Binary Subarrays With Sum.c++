class Solution
{
    int help(vector<int> &nums, int goal)
    {
        int ret = 0;
        int l = 0;
        int psum = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            psum += nums[r];
            while (psum > goal && l <= r)
                psum -= nums[l++];

            ret += (r - l + 1);
        }

        return ret;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return help(nums, goal) - help(nums, goal - 1);
    }
};