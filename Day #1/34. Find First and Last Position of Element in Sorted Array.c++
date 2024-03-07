class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        vector<int>sol = {-1, -1};

        int n = nums.size();

        int l = 0;
        int r = n - 1;
        int mid = l + (r - l) / 2;

        while (l <= r)
        {
            if (nums[mid] == target)
            {
                sol[0] = mid;
                r = mid - 1;
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
            mid = l + (r - l) / 2;
        }

        l = 0;
        r = n - 1;
        mid = l + (r - l) / 2;
        while (l <= r)
        {
            if (nums[mid] == target)
            {
                sol[1] = mid;
                l = mid + 1;
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
            mid = l + (r - l) / 2;
        }
        return sol;
    }
};

