class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<list<int>> graph(n);
        vector<int> nofe(n, 0);
        vector<int> sol;
        for (auto &it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            nofe[it[0]]++;
            nofe[it[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (nofe[i] == 1)
                q.push(i);
        }
        int visited = 0;
        while (n - visited > 2)
        {
            visited += q.size();
            int si = q.size();
            for (int i = 0; i < si; i++)
            {
                int curr = q.front();
                q.pop();
                for (auto &it : graph[curr])
                    if (--nofe[it] == 1)
                        q.push(it);
            }
        }

        while (!q.empty())
        {
            sol.emplace_back(q.front());
            q.pop();
        }

        return sol;
    }
};