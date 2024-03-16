class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int p_sum = 0;
        int sol = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            p_sum = nums[i] ? p_sum + 1 : p_sum - 1;
            if (!p_sum)
                sol = max(sol, i + 1);
            else if (m.count(p_sum))
                sol = max(sol, i - m[p_sum]);
            else
                m[p_sum] = i;
        }
        return sol;
    }
};