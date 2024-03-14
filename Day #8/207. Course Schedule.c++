class Solution
{
    bool help(unordered_set<int> &taken, unordered_set<int> &stall, vector<vector<bool>> &graph, int i)
    {
        if (taken.count(i))
            return true;
        if (stall.count(i))
            return false;
        stall.insert(i);
        for (int j = 0; j < graph.size(); j++)
        {
            if (!graph[i][j])
                continue;
            if (!help(taken, stall, graph, j))
                return false;
        }
        stall.erase(i);
        taken.insert(i);
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        for (auto &it : prerequisites)
        {
            graph[it[0]][it[1]] = true;
        }
        unordered_set<int> taken;
        unordered_set<int> stall;

        for (int i = 0; i < numCourses; i++)
        {
            if (!help(taken, stall, graph, i))
                return false;
        }
        return true;
    }
};