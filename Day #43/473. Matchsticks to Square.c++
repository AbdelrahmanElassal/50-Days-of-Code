class Solution
{
    int n;
    bool help(vector<int> &ms, vector<int> &sides, int i)
    {
        if (i >= n)
            return !sides[0] && !sides[1] && !sides[2] && !sides[3];

        for (int j = 0; j < 4; j++)
        {
            if (ms[i] <= sides[j])
            {
                sides[j] -= ms[i];
                if (help(ms, sides, i + 1))
                    return true;
                sides[j] += ms[i];
            }
        }

        return false;
    }

public:
    bool makesquare(vector<int> &ms)
    {
        sort(ms.rbegin(), ms.rend());
        int sum = 0;
        for (auto &it : ms)
            sum += it;
        if (sum % 4)
            return false;
        sum /= 4;
        vector<int> sides(4, sum);
        n = ms.size();
        return help(ms, sides, 0);
    }
};