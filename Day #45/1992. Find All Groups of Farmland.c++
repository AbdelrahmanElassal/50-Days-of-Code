class Solution
{
    int n, m;
    void mark(vector<vector<int>> &land, int i, int j, int &l, int &w)
    {
        if (i >= n || j >= m || land[i][j] != 1)
        {
            l = max(i - 1, l);
            w = max(j - 1, w);
            return;
        }
        land[i][j] = -1;
        mark(land, i + 1, j, l, w);
        mark(land, i, j + 1, l, w);
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        n = land.size();
        m = land[0].size();
        int l = 0;
        int w = 0;
        vector<vector<int>> sol;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (land[i][j] == 1)
                {
                    mark(land, i, j, l, w);
                    sol.push_back({i, j, l, w});
                    l = 0;
                    w = 0;
                }
            }
        }

        return sol;
    }
};