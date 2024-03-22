//Solution 1:
class Solution1
{
    int n;
    int m;
    void checkBord(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        checkBord(grid, i + 1, j);
        checkBord(grid, i - 1, j);
        checkBord(grid, i, j + 1);
        checkBord(grid, i, j - 1);
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int onecounts = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            checkBord(grid, i, 0);
            checkBord(grid, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            checkBord(grid, 0, j);
            checkBord(grid, n - 1, j);
        }

        for (auto &it : grid)
        {
            for (auto &iy : it)
            {
                if (iy)
                    onecounts++;
            }
        }

        return onecounts;
    }
};

//Solution 2:

class Solution2
{
    int n;
    int m;
    int checkBord(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0 || visited[i][j])
            return 0;
        visited[i][j] = true;
        return 1 + checkBord(grid, visited, i + 1, j) + checkBord(grid, visited, i - 1, j) + checkBord(grid, visited, i, j + 1) + checkBord(grid, visited, i, j - 1);
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int onecounts = 0;
        int borderones = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                    onecounts++;
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] && !visited[i][j])
                {
                    borderones += checkBord(grid, visited, i, j);
                }
            }
        }

        return onecounts - borderones;
    }
};