class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {

        stack<int> s;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            while (!s.empty() && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
            s.push(pushed[i]);
        }

        while (!s.empty() && j < pushed.size() && s.top() == popped[j++])
        {
            s.pop();
        }

        return s.empty();
    }
};