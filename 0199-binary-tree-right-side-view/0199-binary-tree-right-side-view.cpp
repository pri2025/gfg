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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> level;

            for(int i =0; i<n;i++){
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        
        for(int i =0; i<res.size();i++){
            int m = res[i].size();
            ans.push_back(res[i][m-1]);
        }
        return ans;

        
    }
};