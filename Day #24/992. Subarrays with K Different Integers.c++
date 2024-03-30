class Solution
{
    int n;

public:
    int help(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int i = 0, right = 0, count = 0;

        while (right < n)
        {
            m[nums[right]]++;
            while (i <= right && m.size() > k)
            {
                if (--m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
            count += (right - i + 1);
            right++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        n = nums.size();
        return help(nums, k) - help(nums, k - 1);
    }
};