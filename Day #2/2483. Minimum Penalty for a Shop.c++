class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int Y = 0;
        int N = 0;
        for (auto &it : customers)
        {
            if (it == 'Y')
                Y++;
        }

        int minPen = INT_MAX;
        int sol = 0;
        for (int i = 0; i <= customers.length(); i++)
        {
            if (minPen > (Y + N))
            {
                minPen = (Y) + (N);
                sol = i;
            }
            if (i < customers.length())
                customers[i] == 'Y' ? Y-- : N++;
        }

        return sol;
    }
};