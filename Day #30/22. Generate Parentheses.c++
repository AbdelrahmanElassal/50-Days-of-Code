class Solution
{
    vector<string> sol;
    int nn;
    void help(int o, int c, string s)
    {
        if (o == nn && c == nn)
        {
            sol.push_back(s);
        }

        if (o < nn)
            help(o + 1, c, s + "(");
        if (o > c)
            help(o, c + 1, s + ")");
    }

public:
    vector<string> generateParenthesis(int n)
    {
        nn = n;
        help(0, 0, "");
        return sol;
    }
};