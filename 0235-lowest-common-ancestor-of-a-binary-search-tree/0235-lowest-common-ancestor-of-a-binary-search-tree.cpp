/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        //range [p,q);
        while(root != nullptr){

            if(root->val > q->val && root->val > p->val){
                root= root->left;
            }
            else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else
            return root;
        }
        return nullptr;
    }
};