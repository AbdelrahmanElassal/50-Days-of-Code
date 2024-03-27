class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
    {
        vector<long long> ans(nums.size());
        unordered_map<int, long long> m;
        priority_queue<pair<long long, int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = (m.count(nums[i])) ? m[nums[i]] += freq[i] : m[nums[i]] = freq[i];
            pq.push({m[nums[i]], nums[i]});
            auto it = pq.top();
            while (!pq.empty() && it.first != m[it.second])
            {
                pq.pop();
                it = pq.top();
            }
            ans[i] = it.first;
        }

        return ans;
    }
};