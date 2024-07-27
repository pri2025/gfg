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
    int fn(TreeNode* root){
        if(root == nullptr) return 0 ;

        int l = fn(root->left);
        if(l == -1) return -1;
        
        int r = fn(root->right);
        if(r == -1) return -1;

        if(abs(l-r) > 1) return -1;


        int a = max(l,r) + 1;
        return a;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(fn(root) != -1) return true;

        return false;
    }
};