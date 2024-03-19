class Solution
{

public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](vector<int> &l, vector<int> &r)
             { return r[1] > l[1]; });

        int curr = pairs[0][1];
        int len = 1;
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i][0] > curr)
            {
                len++;
                curr = pairs[i][1];
            }
        }

        return len;
    }
};



//--> OLD SOLUTION (ACCEPTED)

// class Solution
// {
//     int help(vector<vector<int>> &pairs, int i, unordered_map<int, int> &dp)
//     {
//         if (i >= pairs.size())
//             return 0;
//         if (dp.count(i))
//             return dp[i];
//         int maxpai = 0;
//         for (int j = 0; j < pairs.size(); j++)
//         {
//             if (pairs[i][1] < pairs[j][0])
//             {
//                 maxpai = max(maxpai, help(pairs, j, dp));
//             }
//         }

//         return dp[i] = 1 + maxpai;
//     }

// public:
//     int findLongestChain(vector<vector<int>> &pairs)
//     {
//         unordered_map<int, int> dp;
//         for (int i = 0; i < pairs.size(); i++)
//             help(pairs, i, dp);
//         int sol = 0;
//         for (auto it : dp)
//             sol = max(sol, it.second);
//         return sol;
//     }
// };