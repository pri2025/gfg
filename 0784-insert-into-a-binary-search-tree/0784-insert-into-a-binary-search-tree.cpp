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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode* temp = root;
        if(root == nullptr){
            return node;
        }
        while(root != nullptr){
            if(val < root->val && root->left == nullptr){
                root->left = node;
                break;
            }
            else if(val > root->val && root->right == nullptr){
                root->right = node;
                break;
            }
            else if(val < root->val){
                root= root->left;
            }
            else if(val > root->val){
                root = root->right;
            }
        }
        return temp;
    }
};