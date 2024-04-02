class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> sm;
        unordered_map<char, char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (sm.count(s[i]) && sm[s[i]] != t[i])
                return false;
            if (!sm.count(s[i]))
                sm[s[i]] = t[i];
            if (st.count(t[i]) && st[t[i]] != s[i])
                return false;
            if (!st.count(t[i]))
                st[t[i]] = s[i];
        }

        return true;
    }
};