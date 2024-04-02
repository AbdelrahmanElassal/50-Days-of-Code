class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int j = s.length() - 1;
        int sol = 0;
        while (s[j] == ' ')
            j--;
        while (j >= 0 && s[j--] != ' ')
            sol++;

        return sol;
    }
};