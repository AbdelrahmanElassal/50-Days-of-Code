class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &ni)
    {
        int n = intervals.size();
        vector<vector<int>> sol(n + 1);
        int i = 0;
        int j = 0;
        while (i < n && ni[0] > intervals[i][1])
        {
            sol[j++] = intervals[i];
            i++;
        }

        while (i < n && ni[1] >= intervals[i][0])
        {
            ni = {min(ni[0], intervals[i][0]), max(ni[1], intervals[i][1])};
            i++;
        }
        sol[j++] = ni;

        while (i < n)
        {
            sol[j++] = intervals[i++];
        }

        sol.resize(j);
        return sol;
    }
};