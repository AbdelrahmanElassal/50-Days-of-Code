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
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> Graph;
        constructgraph(root, Graph);
        vector<bool> visited(100001, false);
        int sol = 0;
        traverse(Graph, visited, start, sol, 0);
        return sol;
    }

    void traverse(unordered_map<int, vector<int>> &Graph, vector<bool> &visited, int curr, int &sol, int len)
    {
        visited[curr] = true;
        sol = max(sol, len);
        for (auto &it : Graph[curr])
        {
            if (visited[it] != true)
            {
                traverse(Graph, visited, it, sol, len + 1);
            }
        }
    }

    void constructgraph(TreeNode *root, unordered_map<int, vector<int>> &Graph)
    {
        if (!root)
            return;

        if (root->right)
        {
            Graph[root->val].push_back(root->right->val);
            Graph[root->right->val].push_back(root->val);
        }

        if (root->left)
        {
            Graph[root->val].push_back(root->left->val);
            Graph[root->left->val].push_back(root->val);
        }

        constructgraph(root->left, Graph);
        constructgraph(root->right, Graph);
    }
};