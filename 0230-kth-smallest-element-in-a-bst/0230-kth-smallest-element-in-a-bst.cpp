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
    
    void fn(TreeNode* root, int k,stack<int> &st,int &cnt){
        if(cnt >= k || root == nullptr){
            return;
        }

        fn(root->left, k,st,cnt);
        if(cnt < k){
            st.push(root->val);
            cnt++;
        }
        
        fn(root->right,k,st,cnt);

    }
    int kthSmallest(TreeNode* root, int k) {
        stack<int> st; int cnt = 0;
        fn(root,k,st,cnt);
        int t = st.top();
        return t;
        
    }
};