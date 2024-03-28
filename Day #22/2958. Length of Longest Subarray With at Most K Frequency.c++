class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int l = 0;
        int r;
        int sol = 0;
        for (r = 0; r < nums.size(); r++)
        {
            m[nums[r]]++;
            while (l < r && m[nums[r]] > k)
                m[nums[l++]]--;
            sol = max(sol, r - l + 1);
        }

        return sol;
    }
};