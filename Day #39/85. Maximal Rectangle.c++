class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> bars(m, 0);
        int area = 0;

        for (auto &row : matrix)
        {
            for (int j = 0; j < m; j++)
            {
                bars[j] = row[j] == '1' ? bars[j] + 1 : 0;
            }

            stack<int> st;
            for (int i = 0; i < m; i++)
            {
                while (!st.empty() && bars[st.top()] > bars[i])
                {
                    int l = bars[st.top()];
                    st.pop();
                    int w = st.empty() ? i : i - st.top() - 1;
                    area = max(area, l * w);
                }
                st.push(i);
            }
            while (!st.empty())
            {
                int l = bars[st.top()];
                st.pop();
                int w = st.empty() ? m : m - st.top() - 1;
                area = max(area, l * w);
            }
        }
        return area;
    }
};