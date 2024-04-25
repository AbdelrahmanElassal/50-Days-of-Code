class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        sort(trips.begin(), trips.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        priority_queue<pair<int, int>> fin;
        int pass = 0;
        for (auto &it : trips)
        {
            while (!fin.empty() && fin.top().first * -1 <= it[1])
            {
                pass -= fin.top().second;
                fin.pop();
            }
            fin.push({-1 * it[2], it[0]});
            pass += it[0];
            if (pass > capacity)
                return false;
        }

        return true;
    }
};