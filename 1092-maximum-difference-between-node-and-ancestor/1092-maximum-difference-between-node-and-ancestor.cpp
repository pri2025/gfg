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
int diff = INT_MIN;
    void fn(TreeNode* root, int mini,int maxi){
        if(root == nullptr){
            diff = max(diff,abs(maxi-mini));
            return;
        }
        mini = min(mini,root->val);
        maxi = max(maxi,root->val);

        fn(root->left, mini,maxi);
        fn(root->right, mini,maxi);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = root->val; int maxi = root->val;
        fn(root,mini ,maxi);
        return diff;
    }
};