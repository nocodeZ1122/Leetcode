/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    unordered_map<string,int> mp;
    vector<TreeNode*> ans;

    string dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return "#";
        }

        string left = dfs(root->left);

        string right = dfs(root->right);

        string curr = to_string(root->val) + "," + left + "," + right;

        mp[curr]++;

        if(mp[curr] == 2)
        {
            ans.push_back(root);
        }

        return curr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        dfs(root);

        return ans;
    }
};