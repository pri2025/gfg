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
    void fn(TreeNode* root, int t,vector<vector<int>> &res,vector<int> &ans,int curr){
        if(root == nullptr) return;

        curr += root->val;
        ans.push_back(root->val);
        if(curr == t && root->left == nullptr && root->right == nullptr){
            res.push_back(ans);
          
        }                                                                                      
        else{
            fn(root->left,t,res,ans,curr);
            fn(root->right,t,res,ans,curr);
        }
        ans.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> ans;
        int curr = 0;
        fn(root,targetSum,res,ans,curr);
        return res;

    }
};