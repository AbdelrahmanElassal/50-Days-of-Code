class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> hash;
        for (auto &it : wordDict)
            hash.insert(it);
        queue<int> ends;
        vector<bool> visited(s.length(), false);
        ends.push(0);
        while (!ends.empty())
        {
            int start = ends.front();
            ends.pop();
            if (start == s.length())
                return true;

            for (int i = start + 1; i <= s.length(); i++)
            {
                if (visited[i])
                    continue;
                if (hash.count(s.substr(start, i - start)))
                {
                    ends.push(i);
                    visited[i] = true;
                }
            }
        }

        return false;
    }
};