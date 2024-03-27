class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        unordered_map<char, int> freq;
        int l = 0;
        int r;
        int sol = 0;
        for (r = 0; r < s.length(); r++)
        {
            freq[s[r]]++;
            while (freq[s[r]] > 2)
            {
                freq[s[l++]]--;
            }
            sol = max(sol, r - l + 1);
        }

        return sol;
    }
};