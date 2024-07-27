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
        if(root == nullptr) return INT_MAX;

        if(root->left == nullptr &&root->right == nullptr) return 1;
        //leaf node pr hum vaise bhi 1 hi return krte max(0,0)+1; 

        int l = fn(root->left);
        int r = fn(root->right);

        int curr = min(l,r) + 1;
 
        
        return curr;
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        return fn(root);
      

    }
};