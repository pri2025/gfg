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

    //     fn(root->left, res);
    //     res.push_back(root->val);
    //     fn(root->right, res);
    // }
    //fn(root, res);
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        //st.push(root);
        while(!st.empty() || node != NULL){
            while(node != NULL){
                st.push(node);
                node = node->left;
            }
            //if(st.empty()) break;
            node = st.top();
            st.pop();
            res.push_back(node->val);
            node= node->right;          
        }
        return res;
    }
};