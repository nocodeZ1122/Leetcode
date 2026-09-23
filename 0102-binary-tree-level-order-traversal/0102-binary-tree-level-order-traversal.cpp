class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if(root == NULL)
            return res;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int levelsize = q.size();

            vector<int> temp;

            for(int i = 0; i < levelsize; i++)
            {
                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if(t->left)
                    q.push(t->left);

                if(t->right)
                    q.push(t->right);
            }

            res.push_back(temp);
        }

        return res;
    }
};