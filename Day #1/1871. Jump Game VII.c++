class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.length() - 1;
        int j = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i == 0 || s[i] == 'r')
            {
                for (j = max(i + minJump, j); j <= min(n, i + maxJump); j++)
                {
                    if (s[j] == '0')
                        s[j] = 'r';
                }
            }
        }

        return s[n] == 'r';
    }
};



