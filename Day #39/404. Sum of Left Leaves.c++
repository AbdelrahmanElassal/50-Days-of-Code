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
    int sum;
    void help(TreeNode *root, bool flag)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            if (flag)
                sum += root->val;
            return;
        }
        help(root->left, true);
        help(root->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        sum = 0;
        help(root, false);
        return sum;
    }
};