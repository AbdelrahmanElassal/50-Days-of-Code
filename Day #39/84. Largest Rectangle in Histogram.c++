class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int l = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                area = max(area, l * w);
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int l = heights[st.top()];
            st.pop();
            int w = st.empty() ? n : n - st.top() - 1;
            area = max(area, l * w);
        }

        return area;
    }
};