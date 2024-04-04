class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<pair<char, int>> row;
        set<pair<char, int>> col;
        set<pair<char, int>> box;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char el = board[i][j];
                int fact = i / 3 * 3 + j / 3;
                if (el != '.')
                {
                    if (row.find({el, i}) != row.end())
                        return false;
                    else
                        row.insert({el, i});

                    if (col.find({el, j}) != col.end())
                        return false;
                    else
                        col.insert({el, j});

                    if (box.find({el, fact}) != box.end())
                        return false;
                    else
                        box.insert({el, fact});
                }
            }
        }

        return true;
    }
};