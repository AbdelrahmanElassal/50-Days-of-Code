/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    void help(TreeNode *root, string &sol, string curr)
    {
        if (!root)
            return;
        curr += char('a' + root->val);
        if (!root->left && !root->right)
        {
            reverse(curr.begin(), curr.end());
            if (sol.empty() || sol > curr)
                sol = curr;
            reverse(curr.begin(), curr.end());
        }

        help(root->left, sol, curr);
        help(root->right, sol, curr);
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        string sol;
        help(root, sol, "");
        return sol;
    }
};