class Solution
{
public:
    string customSortString(string order, string s)
    {

        unordered_map<char, int> sm;

        for (auto &it : order)
            sm[it] = 0;
        for (auto &it : s)
        {
            if (sm.count(it))
                sm[it]++;
        }

        string sol = s;
        int i = 0;
        for (auto &it : order)
        {
            while (sm[it]-- > 0)
            {
                sol[i++] = it;
            }
        }

        for (auto &it : s)
        {
            if (!sm.count(it))
            {
                sol[i++] = it;
            }
        }

        return sol;
    }
};