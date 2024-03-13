class Solution
{
    int n;
    void calcDistanceFromNode(vector<int> &dist, int base, int prev, int curr, vector<int> &edges)
    {
        if (curr == base || curr == -1 || dist[curr] != -1)
            return;
        dist[curr] = dist[prev] + 1;
        calcDistanceFromNode(dist, base, curr, edges[curr], edges);
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        n = edges.size();
        vector<int> dist1(n, -1);
        dist1[node1] = 0;
        calcDistanceFromNode(dist1, node1, node1, edges[node1], edges);
        vector<int> dist2(n, -1);
        dist2[node2] = 0;
        calcDistanceFromNode(dist2, node2, node2, edges[node2], edges);

        int sol = -1;
        int mindist = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (dist1[i] != -1 && dist2[i] != -1 && max(dist1[i], dist2[i]) < mindist)
            {
                sol = i;
                mindist = max(dist1[i], dist2[i]);
            }
        }
        return sol;
    }
};