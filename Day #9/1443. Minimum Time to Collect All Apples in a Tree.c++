class Solution
{
    int help(vector<vector<int>> &tree, int prev, int curr, vector<bool> &hasApple)
    {
        int sum = 0;
        for (auto &it : tree[curr])
            if (it != prev)
                sum += help(tree, curr, it, hasApple);
        if (!curr)
            return sum;
        if (sum)
            return sum + 2;
        else
            return hasApple[curr] ? 2 : 0;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> tree(n);
        for (auto &it : edges)
            tree[it[0]].push_back(it[1]), tree[it[1]].push_back(it[0]);
        return help(tree, -1, 0, hasApple);
    }
};