class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        unordered_map<int, int> m;
        int l = 0;
        int sol = 0;
        for (int i = 0; i < n; i++)
        {
            m[fruits[i]] = i;
            if (m.size() > 2)
            {
                pair<int, int> iy = {0, n};
                for (auto &it : m)
                {
                    if (it.second < iy.second)
                        iy = it;
                }
                m.erase(iy.first);
                sol = max(sol, i - l);
                l = iy.second + 1;
            }
            sol = max(sol, i - l + 1);
        }

        return sol;
    }
};