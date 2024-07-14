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
    // void fn2(TreeNode* root2, vector<int> &in2){
    //     if(root2 == NULL){
    //         return;
    //     }

    //     in2.push_back(root2->val);
    //     fn2(root2->left,in2);
    //     fn2(root2->right,in2);
    // }
    // void fn(TreeNode* root1,vector<int> &in1){
    //     if(root1 == NULL){
    //         return;
    //     }

    //     in1.push_back(root1->val);
    //     fn(root1->left,in1);
    //     fn(root1->right,in1);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //vector<int>in1, in2;
        if(p == NULL && q == NULL) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        // fn(p,in1);
        // fn2(q,in2);
        // if(in1 == in2){
        //     return true;
        // }
        // return false;
    }
};