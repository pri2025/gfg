class Solution {
public:
    void fn(int index,vector<int>& nums,vector<int> &ans,vector<vector<int>> &res){
        if(index == nums.size()){
            res.push_back(ans);
            return;
        }

        ans.push_back(nums[index]);
        fn(index+1,nums,ans,res);
        ans.pop_back();
        fn(index+1,nums,ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int index = 0;
        fn(0,nums,ans,res);
        return res;   
    }
};