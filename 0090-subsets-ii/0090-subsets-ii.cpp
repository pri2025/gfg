class Solution {
public:
    void fn(int index,vector<int>& nums,vector<int> cnt,vector<vector<int>> &res ){

        res.push_back(cnt);
       

        for(int i = index; i<nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            cnt.push_back(nums[i]);
            fn(i+1,nums,cnt,res);
            cnt.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cnt;
        sort(nums.begin(),nums.end());
        fn(0,nums,cnt,res);
        return res;
    }
};