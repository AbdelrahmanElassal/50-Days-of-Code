class Solution
{
public:
    int pivotInteger(int n)
    {
        double x = sqrt(n * (n + 1) / 2);

        x == (int)x ? x = x : x = -1;
        return x;
    }
};