class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> stars;
        stack<int> para;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '(')
                para.push(i);

            else if (s[i] == ')')
            {
                if (!para.empty())
                    para.pop();

                else if (!stars.empty())
                    stars.pop();

                else
                    return false;
            }

            else
                stars.push(i);
        }

        if (para.empty())
            return true;

        while (!para.empty() && !stars.empty())
        {
            if (para.top() < stars.top())
            {
                para.pop();
                stars.pop();
            }
            else
                return false;
        }
        return para.empty();
    }
};