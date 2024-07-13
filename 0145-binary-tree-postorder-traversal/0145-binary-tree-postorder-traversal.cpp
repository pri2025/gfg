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
    // void fn(TreeNode* root, vector<int> &res){
    //     if(root == NULL) return;

    //     fn(root->left,res);
    //     fn(root->right,res);
    //     res.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        //fn(root, res);
        stack<TreeNode*> st1; stack<int> st2;

        st1.push(root);
        while(!st1.empty()){
            TreeNode* node= st1.top();
            st1.pop();
            st2.push(node->val);
            if(node->left != NULL){
                st1.push(node->left);
            }
            if(node->right != NULL){
                st1.push(node->right);
            }
            
        }
        vector<int> res;
        while(!st2.empty()){
            res.push_back(st2.top());
            st2.pop();
        }
        return res;
    }
};