class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 1)
            return 1;
        sort(points.begin(), points.end());
        int count = 1;
        int end = points[0][1];
        for (auto &it : points)
        {
            if (it[0] > end)
            {
                end = it[1];
                count++;
            }
            end = min(end, it[1]);
        }

        return count;
    }
};