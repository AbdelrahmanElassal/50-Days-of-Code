class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26);
        for (auto &it : tasks)
        {
            freq[it - 'A']++;
        }
        priority_queue<int> pq;
        for (auto &it : freq)
        {
            if (it)
                pq.push(it);
        }

        int sol = 0;
        while (!pq.empty())
        {
            vector<int> unproccess;
            int cy = n + 1;
            int count = 0;

            while (!pq.empty() && cy-- > 0)
            {
                if (pq.top() > 1)
                    unproccess.emplace_back(pq.top() - 1);
                count++;
                pq.pop();
            }

            for (auto &it : unproccess)
                pq.push(it);
            sol = pq.empty() ? sol + count : sol + n + 1;
        }
        return sol;
    }
};