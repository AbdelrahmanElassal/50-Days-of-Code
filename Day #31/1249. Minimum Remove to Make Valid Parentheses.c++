class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {

        string temp = "";
        int o = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                o++;
            }
            else if (s[i] == '(')
            {
                if (o)
                {
                    o--;
                }
                else
                    continue;
            }
            temp += s[i];
        }
        o = 0;
        string sol = "";
        for (int i = temp.length() - 1; i >= 0; i--)
        {
            if (temp[i] == '(')
            {
                o++;
            }
            else if (temp[i] == ')')
            {
                if (o)
                {
                    o--;
                }
                else
                    continue;
            }
            sol += temp[i];
        }

        return sol;
    }
};