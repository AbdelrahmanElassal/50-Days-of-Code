class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int r;
        int l = 0;
        int sum = 0;
        int sol = 0;
        for (r = 0; r < k; r++)
        {
            sum += arr[r];
        }
        while (r < arr.size())
        {
            if (sum / k >= threshold)
                sol++;
            sum -= arr[l++];
            sum += arr[r++];
        }
        if (sum / k >= threshold)
            sol++;
        return sol;
    }
};