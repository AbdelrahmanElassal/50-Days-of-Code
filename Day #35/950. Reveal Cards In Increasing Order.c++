class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> sol(n);
        queue<int> sim;
        for (int i = 0; i < n; i++)
            sim.push(i);
        int i = 0;
        while (!sim.empty())
        {
            int curr = sim.front();
            sim.pop();
            sol[curr] = deck[i++];
            curr = sim.front();
            sim.pop();
            sim.push(curr);
        }

        return sol;
    }
};