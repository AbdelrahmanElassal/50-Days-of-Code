class Solution
{
    bool help(int curr, int destination, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited)
    {
        if (curr == destination)
            return true;

        visited.insert(curr);
        for (auto &it : graph[curr])
        {
            if (!visited.count(it))
            {
                if (help(it, destination, graph, visited))
                    return true;
            }
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> graph;
        for (auto &it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        unordered_set<int> visited;
        return help(source, destination, graph, visited);
    }
};