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
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);

        int currDepth = 1;

        while(!q.empty())
        {
            int n = q.size();

            for(int i = 0; i < n; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(currDepth == depth - 1)
                {
                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* rightNode = new TreeNode(val);

                    leftNode->left = curr->left;
                    rightNode->right = curr->right;

                    curr->left = leftNode;
                    curr->right = rightNode;
                }
                else
                {
                    if(curr->left)
                        q.push(curr->left);

                    if(curr->right)
                        q.push(curr->right);
                }
            }

            if(currDepth == depth - 1)
                break;

            currDepth++;
        }

        return root;
    }
};