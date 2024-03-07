class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> avTasks;
        vector<int> sol(n);
        for (int i = 0; i < n; i++)
        {
            pq.push({tasks[i][0], tasks[i][1], i});
        }

        long long time = pq.top()[0];
        int i = 0;
        while (!pq.empty())
        {
            while (!pq.empty() && pq.top()[0] <= time)
            {
                avTasks.push({pq.top()[1], pq.top()[2], pq.top()[0]});
                pq.pop();
            }

            if (avTasks.empty())
            {
                time = pq.top()[0];
                continue;
            }

            sol[i++] = avTasks.top()[1];
            time += avTasks.top()[0];
            avTasks.pop();
        }

        while (!avTasks.empty())
        {
            sol[i++] = avTasks.top()[1];
            avTasks.pop();
        }

        return sol;
    }
};