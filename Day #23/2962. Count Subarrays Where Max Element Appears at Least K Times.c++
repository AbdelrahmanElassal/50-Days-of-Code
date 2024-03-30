class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long sol = 0;
        int maxel = *max_element(nums.begin(), nums.end()), count = 0, l = 0, r;

        for (r = 0; r < n; r++)
        {
            count = nums[r] == maxel ? count + 1 : count;
            while (count >= k)
            {
                sol += (n - r);
                if (nums[l++] == maxel)
                    count--;
            }
        }

        return sol;
    }
};