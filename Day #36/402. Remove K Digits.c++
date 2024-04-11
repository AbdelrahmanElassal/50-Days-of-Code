class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();
        if (n <= k)
            return "0";

        stack<char> mon;
        int i = 0;
        int c = k;
        for (i = 0; i < n; i++)
        {
            while (k && !mon.empty() && mon.top() > num[i])
            {
                mon.pop();
                k--;
            }
            mon.push(num[i]);
        }
        while (k--)
            mon.pop();
        string res = "";
        while (!mon.empty())
        {
            res += mon.top();
            mon.pop();
        }
        reverse(res.begin(), res.end());
        string fin = "";
        int j;
        for (j = 0; j < res.length(); j++)
        {
            if (res[j] != '0')
                break;
        }

        for (j; j < res.length(); j++)
        {
            fin += res[j];
        }
        return fin == "" ? "0" : fin;
    }
};