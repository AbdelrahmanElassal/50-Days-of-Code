class Solution
{
    int sol;
    void dfs(unordered_set<int> &s, vector<vector<vector<int>>> &m, int i)
    {
        if (s.count(i))
            return;

        s.insert(i);
        for (auto &it : m[i])
        {
            sol = min(sol, it[1]);
            dfs(s, m, it[0]);
        }
    }

public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        sol = INT_MAX;
        unordered_set<int> s;
        vector<vector<vector<int>>> m(n + 1);
        for (auto &it : roads)
        {
            m[it[0]].push_back({it[1], it[2]});
            m[it[1]].push_back({it[0], it[2]});
        }

        dfs(s, m, 1);

        return sol;
    }
};