class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> fr;
        vector<int> sol;
        for (auto &it : nums1)
        {
            fr.insert(it);
        }

        for (auto &it : nums2)
        {
            if (fr.find(it) != fr.end())
            {
                sol.emplace_back(it);
                fr.erase(it);
            }
        }

        return sol;
    }
};