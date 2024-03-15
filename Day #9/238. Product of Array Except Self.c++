class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 2)
        {
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            return nums;
        }
        vector<int> sol(n);
        vector<int> temp1(n, 1);
        vector<int> temp2(n, 1);

        for (int i = 1; i < n; i++)
        {
            temp1[i] = nums[i - 1] * temp1[i - 1];
            temp2[n - 1 - i] = nums[n - i] * temp2[n - i];
        }
        for (int i = 0; i < n; i++)
        {
            sol[i] = temp1[i] * temp2[i];
        }

        return sol;
    }
};