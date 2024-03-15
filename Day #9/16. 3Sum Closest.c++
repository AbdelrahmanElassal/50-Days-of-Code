class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int n = nums.size();
        int sol = 0;
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int curr = nums[i] + nums[l] + nums[r];
                if (curr == target)
                    return curr;
                if (abs(curr - target) < diff)
                {
                    diff = abs(curr - target);
                    sol = curr;
                }
                else if (curr > target)
                    r--;
                else
                    l++;
            }
        }

        return sol;
    }
};