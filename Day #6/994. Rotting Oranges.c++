class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> qu;
        bool controtten = false;
        bool contor = false;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                    contor = true;
                if (grid[i][j] == 2)
                {
                    qu.push({i, j});
                    controtten = true;
                }
            }
        }
        if (controtten == false && contor == false)
            return 0;
        if (controtten == false && contor)
            return -1;
        int res = -1;
        vector<int> trax = {1, -1, 0, 0};
        vector<int> tray = {0, 0, 1, -1};
        while (!qu.empty())
        {
            int si = qu.size();
            for (int i = 1; i <= si; i++)
            {
                pair<int, int> temp = qu.front();
                qu.pop();
                visited[temp.first][temp.second] = true;

                for (int count = 0; count < 4; count++)
                {
                    int x = temp.first + trax[count];
                    int y = temp.second + tray[count];
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !visited[x][y] && grid[x][y] == 1)
                    {
                        grid[temp.first + trax[count]][temp.second + tray[count]] = 2;
                        qu.push({temp.first + trax[count], temp.second + tray[count]});
                    }
                }
            }
            res++;
        }

        for (auto &it : grid)
        {
            for (auto &it2 : it)
            {
                if (it2 == 1)
                    return -1;
            }
        }

        return res;
    }
};