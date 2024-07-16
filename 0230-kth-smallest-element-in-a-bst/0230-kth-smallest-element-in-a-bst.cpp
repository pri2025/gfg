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
    
    void fn(TreeNode* root, int k,int &s,int &cnt){
        if(cnt >= k || root == nullptr){
            return;
        }

        fn(root->left, k,s,cnt);
        cnt++;
        if(cnt == k){
            s = root->val;//st.push(root->val);
            //cnt++; 
            return;
        }
        
        fn(root->right,k,s,cnt);

    }
    int kthSmallest(TreeNode* root, int k) {
        //stack<int> st; 
        int s = INT_MAX;
        int cnt = 0;
        fn(root,k,s,cnt);
        return s;
        //return st.top();
    }
};