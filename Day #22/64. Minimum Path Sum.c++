class Solution
{
    int n;
    int m;
    int help(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {
        if (i == n - 1 && j == m - 1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = i < n - 1 ? help(grid, dp, i + 1, j) : -1;
        int right = j < m - 1 ? help(grid, dp, i, j + 1) : -1;
        if (down == -1)
            down = INT_MAX;
        if (right == -1)
            right = INT_MAX;
        if (down == INT_MAX && right == INT_MAX)
            return dp[i][j] = INT_MAX;
        return dp[i][j] = grid[i][j] + min(down, right);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return help(grid, dp, 0, 0);
    }
};