class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || s[i] != st.top().first)
                st.push({s[i], 1});
            else
            {
                if (s[i] == st.top().first && st.top().second == k - 1)
                {
                    while (!st.empty() && st.top().first == s[i])
                        st.pop();
                }
                else if (s[i] == st.top().first)
                    st.push({s[i], st.top().second + 1});
            }
        }
        s = "";
        while (!st.empty())
        {
            s.append(1u, st.top().first);
            st.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }
};