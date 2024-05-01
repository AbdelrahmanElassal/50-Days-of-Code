class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int x = nums[0];
        int sol = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            x = x ^ nums[i];
        }
        for (int i = 0; i < 32; i++)
        {
            if ((x & 1 << i) != (k & 1 << i))
                sol++;
        }
        return sol;
    }
};