class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() && abs(st.top() - s[i]) == 32)
                st.pop();
            else
                st.push(s[i]);
        }

        string sol = "";
        while (!st.empty())
        {
            sol += st.top();
            st.pop();
        }

        reverse(sol.begin(), sol.end());
        return sol;
    }
};