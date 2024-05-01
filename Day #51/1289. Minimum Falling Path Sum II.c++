class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                int curr = INT_MAX;
                for (int k = 0; k < m; k++)
                {
                    if (k != j)
                        curr = min(curr, grid[i + 1][k]);
                }
                grid[i][j] = grid[i][j] + curr;
            }
        }

        int sol = INT_MAX;
        for (auto &it : grid[0])
            sol = min(sol, it);

        return sol;
    }
};