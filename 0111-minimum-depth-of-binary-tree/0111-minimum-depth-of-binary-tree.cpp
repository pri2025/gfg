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
 
    // int fn(TreeNode* root){
    //     if(root == nullptr) return INT_MAX;
    //     //because min choose krna hai to agr 0 return kra to 1 hi return kri jayega

    //     if(root->left == nullptr &&root->right == nullptr) return 1;
    //     //leaf node pr hum vaise bhi 1 hi return krte max(0,0)+1; 

    //     int l = fn(root->left);
    //     int r = fn(root->right);

    //     int curr = min(l,r) + 1;
 
        
    //     return curr;
    // }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n;i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left == nullptr && node->right == nullptr) return depth;

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            depth++;
        }
        return depth;

        //return fn(root);
      

    }
};