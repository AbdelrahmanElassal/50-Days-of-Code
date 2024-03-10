class MajorityChecker
{
    vector<int> MC;
    unordered_map<int, vector<int>> m;

public:
    MajorityChecker(vector<int> &arr)
    {
        this->MC = arr;
        for (int i = 0; i < MC.size(); i++)
        {
            m[MC[i]].push_back(i);
        }
    }

    int query(int l, int r, int threshold)
    {

        for (int i = 0; i < 8; i++)
        {
            int random = this->MC[rand() % (r - l + 1) + l];
            auto left = lower_bound(m[random].begin(), m[random].end(), l);
            auto right = upper_bound(m[random].begin(), m[random].end(), r);
            if (right - left >= threshold)
                return random;
        }

        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */