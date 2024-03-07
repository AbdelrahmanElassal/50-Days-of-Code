class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        // pririty queue for sorting the tasks by there starting time
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // priority queue for sorting the tasks by the shortest task in the same timestamp
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> avTasks; 
        vector<int> sol(n);//the solution which is returned
        
        // a loop to sort the tasks by starting time in pq
        for (int i = 0; i < n; i++)
        {
            pq.push({tasks[i][0], tasks[i][1], i});
        }

        long long time = pq.top()[0];
        int i = 0;
        while (!pq.empty())
        {
            /* pushing tasks that are avaliable in a certain timestamp after a task is being
            handled by the cpu*/
            while (!pq.empty() && pq.top()[0] <= time)
            {
                avTasks.push({pq.top()[1], pq.top()[2], pq.top()[0]});
                pq.pop();
            }
            /*if there are no tasks to handle meaning the cpu is idle the closer task is taken
            to be excuted*/
            if (avTasks.empty())
            {
                time = pq.top()[0];
                continue;
            }
            
            sol[i++] = avTasks.top()[1];
            // increasing the timestamp as the cpu is busy excuting the first aviliable task
            time += avTasks.top()[0]; 
            avTasks.pop();
        }

        // if there are any aviliable tasks remaining they shuold be handled
        while (!avTasks.empty())
        {
            sol[i++] = avTasks.top()[1];
            avTasks.pop();
        }

        return sol;
    }
};