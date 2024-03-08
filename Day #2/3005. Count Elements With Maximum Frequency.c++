class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int maxFreq = 0;
        int sol = 0;
        for (auto &it : nums)
        {
            m[it]++;
            maxFreq = max(maxFreq, m[it]);
        }

        for (auto &it : m)
        {
            if (it.second == maxFreq)
            {
                sol += it.second;
            }
        }

        return sol;
    }
};