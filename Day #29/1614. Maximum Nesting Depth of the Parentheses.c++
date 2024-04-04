class Solution
{
public:
    int maxDepth(string s)
    {
        int sol = 0;
        int op = 0;
        for (auto &it : s)
        {
            if (it == '(')
            {
                op++;
                sol = max(sol, op);
            }
            if (it == ')')
                op--;
        }

        return sol;
    }
};