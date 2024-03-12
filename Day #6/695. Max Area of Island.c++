//--->> RECURSIVE SOLUTION
class Solution
{
    int help(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + help(grid, i + 1, j) + help(grid, i, j + 1) + help(grid, i - 1, j) + help(grid, i, j - 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    ans = max(ans, help(grid, i, j));
                }
            }
        }

        return ans;
    }
};

//--->>ITERATIVE SOLUTION 

// class Solution
// {

// public:
//     int maxAreaOfIsland(vector<vector<int>> &grid)
//     {
//         vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
//         vector<int> r = {0, 0, 1, -1};
//         vector<int> c = {1, -1, 0, 0};
//         int ans = 0;
//         for (int i = 0; i < grid.size(); i++)
//         {
//             for (int j = 0; j < grid[0].size(); j++)
//             {
//                 if (grid[i][j] == 1 && visit[i][j] == false)
//                 {
//                     stack<pair<int, int>> st;
//                     st.push({i, j});
//                     visit[i][j] = true;
//                     int area = 0;
//                     while (!st.empty())
//                     {
//                         pair<int, int> node = {st.top().first, st.top().second};
//                         area++;
//                         st.pop();
//                         for (int coun = 0; coun < 4; coun++)
//                         {
//                             int new_row = node.first + r[coun];
//                             int new_col = node.second + c[coun];

//                             if (new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size() && grid[new_row][new_col] == 1 && visit[new_row][new_col] == false)
//                             {
//                                 st.push({new_row, new_col});
//                                 visit[new_row][new_col] = true;
//                             }
//                         }
//                     }
//                     ans = ::max(ans, area);
//                 }
//             }
//         }
//         return ans;
//     }
// };