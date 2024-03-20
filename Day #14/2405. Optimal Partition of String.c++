class Solution
{
public:
    int partitionString(string s)
    {
        int sol = 1;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (flag & (1 << (s[i] - 'a')))
            {
                flag = 0;
                sol++;
            }
            flag = flag | (1 << (s[i] - 'a'));
        }

        return sol;
    }
};