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
    int d = 0;
    int fn(TreeNode* root){
        if(root== nullptr) return 0;

        int l = fn(root->left);
        int r = fn(root->right);

        int a = max(l,r) + 1;
        d = max(d,a);
        return a;
    }
    int maxDepth(TreeNode* root) {
        fn(root);
        return d;
    }
};