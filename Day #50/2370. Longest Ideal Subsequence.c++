class Solution
{

public:
    int longestIdealString(string s, int k)
    {
        int n = s.length() - 1;
        unordered_map<char, int> m;
        m[s[n]] = 1;
        int sol = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = 1;
            for (int j = 0; j < 26; j++)
            {
                if (m.count(char('a' + j)))
                {
                    if (abs(('a' + j) - s[i]) <= k)
                    {
                        curr = max(curr, m[char('a' + j)] + 1);
                    }
                }
            }
            sol = max(sol, curr);
            m[s[i]] = curr;
        }

        return sol;
    }
};