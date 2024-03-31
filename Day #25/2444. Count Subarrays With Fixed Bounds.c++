class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int l = -1, r = -1, b = -1, n = nums.size();
        long long sol = 0;

        for (int i = 0; i < n; i++)
        {
            if (minK > nums[i] || maxK < nums[i])
                b = i;
            if (nums[i] == minK)
                l = i;
            if (nums[i] == maxK)
                r = i;

            sol += max(0, min(r, l) - b);
        }

        return sol;
    }
};