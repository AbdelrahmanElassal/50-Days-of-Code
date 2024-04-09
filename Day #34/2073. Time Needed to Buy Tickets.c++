class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int sol = 0;

        for (int i = 0; i <= k; i++)
        {
            sol += min(tickets[k], tickets[i]);
        }
        for (int i = k + 1; i < tickets.size(); i++)
        {
            sol += min(tickets[k] - 1, tickets[i]);
        }

        return sol;
    }
};