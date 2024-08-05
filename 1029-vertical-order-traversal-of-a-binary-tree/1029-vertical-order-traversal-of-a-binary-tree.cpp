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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       
        
        map<int,map<int,multiset<int>>> mp;// multiset because duplicates value bhi store ho jaye
        //set because on a same coordinate(same level and vertical) increasing order of values mein nodes chahiye
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            // int n = q.size();
            // for(int i = 0; i<n ; i++){

            // }
            auto it = q.front(); q.pop();
            TreeNode* node = it.first;
            int x = it.second.first; // vertical 
            int y = it.second.second;// horizontal/level
            
            mp[x][y].insert(node->val); //x vertical -> y level -> {} 0 ->0->{1}
                                                                    // 0->1->{5,6}
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>res;

        for(auto it: mp){//vertical
            vector<int> verticalorder;
            for(auto p : it.second){ //vertical->level->set
                verticalorder.insert(verticalorder.end(),p.second.begin(), p.second.end());
            }
            res.push_back(verticalorder);
        }
        
        return res;
    }
};