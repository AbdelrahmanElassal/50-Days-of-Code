// SOL 1
// class Solution
// {
// public:
//     int maximalSquare(vector<vector<char>> &matrix)
//     {
//         int m = matrix[0].size();
//         int n = matrix.size();
//         int sol = 0;

//         vector<vector<pair<int, int>>> coun(n, vector<pair<int, int>>(m, {0, 0}));

//         for (int i = n - 1; i >= 0; i--)
//         {
//             for (int j = m - 1; j >= 0; j--)
//             {
//                 if (matrix[i][j] == '1')
//                 {
//                     if (i == n - 1 && j == m - 1)
//                         coun[i][j] = {1, 1};
//                     else if (j == m - 1)
//                     {
//                         coun[i][j] = {1 + coun[i + 1][j].first, 1};
//                     }
//                     else if (i == n - 1)
//                     {
//                         coun[i][j] = {1, 1 + coun[i][j + 1].second};
//                     }
//                     else
//                     {
//                         coun[i][j] = {1 + coun[i + 1][j].first, 1 + coun[i][j + 1].second};
//                     }
//                 }
//             }
//         }
//         for (int i = n - 1; i >= 0; i--)
//         {
//             for (int j = m - 1; j >= 0; j--)
//             {
//                 if (matrix[i][j] == '1')
//                 {
//                     int side = min(coun[i][j].first, coun[i][j].second);
//                     for (int k = 0; k < side; k++)
//                     {
//                         if (coun[i + k][j].second < side || coun[i][j + k].first < side)
//                         {
//                             side = min(coun[i + k][j].second, coun[i][j + k].first);
//                         }
//                     }
//                     sol = max(sol, side * side);
//                 }
//             }
//         }

//         return sol;
//     }
// };

// SOL 2

//     class Solution
// {
// public:
//     int maximalSquare(vector<vector<char>> &matrix)
//     {
//         int m = matrix[0].size();
//         int n = matrix.size();
//         int side = 0;

//         vector<vector<int>> coun(n, vector<int>(m, 0));

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (matrix[i][j] == '0')
//                     continue;
//                 if (i == 0 || j == 0)
//                     coun[i][j] = 1;
//                 else
//                 {
//                     coun[i][j] = 1 + min(coun[i][j - 1], min(coun[i - 1][j], coun[i - 1][j - 1]));
//                 }
//                 side = max(side, coun[i][j]);
//             }
//         }

//         return side * side;
//     }
// };