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
    // void fn(TreeNode* root,queue<int> &q){
    //     if(root == nullptr) return;

    //     q.push(root->val);
    //     fn(root->left,q);
    //     fn(root->right,q);
    // }
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {

        if(root == nullptr) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;

       // queue<int> q;
        // fn(root,q);

        // TreeNode* curr = root;
        // curr->left = nullptr;
        // q.pop();

        // while(!q.empty()){
          
        //     curr->right = new TreeNode(q.front()); q.pop();
        //     curr = curr->right;
        //     //curr->left = nullptr; 
        // }
       
    }
};