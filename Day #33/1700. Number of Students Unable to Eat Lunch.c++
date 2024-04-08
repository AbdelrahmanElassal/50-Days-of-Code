class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        int zeros = 0, ones = 0;
        for (auto &it : students)
        {
            if (it)
                ones++;
            else
                zeros++;
        }

        for (auto &it : sandwiches)
        {
            if (it)
            {
                if (!ones)
                    return n;
                else
                {
                    n--;
                    ones--;
                }
            }
            else
            {
                if (!zeros)
                    return n;
                else
                {
                    n--;
                    zeros--;
                }
            }
        }

        return 0;
    }
};