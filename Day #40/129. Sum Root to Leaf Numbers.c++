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
public:
    int sumNumbers(TreeNode *root)
    {
        return SN(root, 0);
    }

    int SN(TreeNode *root, int val)
    {
        if (!root)
            return 0;
        val = 10 * val + root->val;
        if (!root->left && !root->right)
            return val;

        int v = SN(root->left, val) + SN(root->right, val);

        return v;
    }
};