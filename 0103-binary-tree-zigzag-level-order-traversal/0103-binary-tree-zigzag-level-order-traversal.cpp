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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> res;
        bool lefttoright = true;
        int index;
        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);
            for(int i = 0; i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(lefttoright){
                     index = i;
                }
                else{
                     index = n-i-1;
                }
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
                level[index]= node->val;
            }
            res.push_back(level);
            lefttoright = !lefttoright;
        }     
        return res;
    }
};