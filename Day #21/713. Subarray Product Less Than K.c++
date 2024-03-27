class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int curr = 1;
        int l = 0;
        int r;
        int sol = 0;
        for (r = 0; r < nums.size(); r++)
        {
            curr *= nums[r];
            while (r >= l && curr >= k)
            {
                curr /= nums[l++];
            }
            sol += (r - l + 1);
        }

        return sol;
    }
};