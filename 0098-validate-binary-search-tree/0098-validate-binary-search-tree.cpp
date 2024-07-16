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
    bool fn(TreeNode* root,long long min, long long max){
       if(root == nullptr) return true;
       if(root->val>=max || root->val <= min) return false;

       return fn(root->left,min,root->val) && fn(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return fn(root, LLONG_MIN, LLONG_MAX);
        
    }
};


//queue<TreeNode*> q;
        // q.push(root);
        // int left = 1,right = 1;

        // while(!q.empty()){
        //     //if(left ==0 && right == 0) return false;
        //     //vector<int> level;
        //     TreeNode* node = q.front(); q.pop();

        //     if(node->left != nullptr){
        //         if(node-> val <= node->left->val){
        //             return false;
        //         }
                
        //         q.push(node->left);
        //     }
        //     if(node->right != nullptr){
        //         if(node->val >= node->right->val){
        //             return false;
        //         }
        //         q.push(node->right);
        //     }
        // }
        // return true;