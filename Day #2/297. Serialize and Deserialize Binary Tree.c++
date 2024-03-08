/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
    void Stringify(TreeNode *root, stringstream &s)
    {
        if (!root)
        {
            s << "Null ";
            return;
        }
        s << root->val;
        s << " ";
        Stringify(root->left, s);
        Stringify(root->right, s);
    }
    TreeNode *buildTree(stringstream &s)
    {
        string num = "";
        s >> num;
        if (num == "Null")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(num));
        root->left = buildTree(s);
        root->right = buildTree(s);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        stringstream s;
        Stringify(root, s);
        return s.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream s(data);

        return buildTree(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));