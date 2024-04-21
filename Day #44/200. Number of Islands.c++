class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int rows = grid.size();
        int colom = grid[0].size();
        int sol = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colom; j++)
            {
                if (vis[i][j] || !grid[i][j])
                    continue;
                sol += help(i, j, grid, vis);
            }
        }
        return sol;
    }
    int help(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || vis[i][j])
            return 0;
        vis[i][j] = true;
        help(i, j + 1, grid, vis);
        help(i + 1, j, grid, vis);
        help(i, j - 1, grid, vis);
        help(i - 1, j, grid, vis);
        return 1;
    }
};