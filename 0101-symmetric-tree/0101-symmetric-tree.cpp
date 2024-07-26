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
    // TreeNode* invert(TreeNode* root){
    //     if(root == nullptr) return root;

    //     TreeNode* left = invert(root->left);
    //     TreeNode* right = invert(root->right);
    //     root->left = right;
    //     root->right = left;
    //     return root;
    // }
    bool same(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        return (p->val == q->val) && same(p->left,q->right) && same(p->right , q->left);
        //return same(p->left, q->left) && same(p->right ,q->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return same(root->left,root->right);
        //TreeNode* root1 = root;
        //TreeNode* newroot = invert(root->left);//sirf ek side invert kro
       // return same(root->right,newroot);//dono subtrees compare kro if same
        
    }
};